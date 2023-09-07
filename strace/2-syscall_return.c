#include "syscall_header.h"
#include "syscalls.h"

int main(int argc, char** argv)
{
        pid_t pid;
        int status, flip;
        struct user_regs_struct regs;

        if (check_arg(argc, argv) == 1)
            exit(EXIT_FAILURE);
        
        pid = fork();
        if (pid == -1)
            exit(EXIT_FAILURE);

        if (pid == 0)
        {
            ptrace(PTRACE_TRACEME, pid, 0, 0);
            kill(getpid(), SIGSTOP);
            execvp(argv[1], argv+1);
            exit(EXIT_FAILURE);
        }
        else
        {
            waitpid(pid, &status, 0);
            ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            for (flip = 1; !WIFEXITED(status); flip ^= 1)
            {
                waitpid(pid, &status, 0);
                memset(&regs, 0, sizeof(regs));
                ptrace(PTRACE_GETREGS, pid, 0, &regs);
                if (flip & !WIFEXITED(status))
                    printf("%s = %#lx\n", syscalls_64_g[regs.orig_rax].name, (long)regs.rax);
                ptrace(PTRACE_SYSCALL, pid, 0, 0);
            }
        }
        printf("exit_group = ?\n");
        return(0);
}
