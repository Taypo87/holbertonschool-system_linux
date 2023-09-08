#include "syscall_header.h"
#include "syscalls.h"

int main(int argc, char** argv, char** envp)
{
        pid_t pid;
        int status, flip, count = 1;
        struct user_regs_struct regs;

        if (check_arg(argc, argv) == 1)
            exit(EXIT_FAILURE);
        setbuf(stdout, NULL);
        pid = fork();
        if (pid == -1)
            exit(EXIT_FAILURE);

        if (pid == 0)
        {
            ptrace(PTRACE_TRACEME, 0, 0, 0);
            kill(getpid(), SIGSTOP);
            execve(argv[1], argv+1, envp);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(&status);
            //ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
            //ptrace(PTRACE_SYSCALL, pid, 0, 0);
            //wait(&status);
            for (flip = 0; !WIFEXITED(status); flip ^= 1)
            {
                memset(&regs, 0, sizeof(regs));
                ptrace(PTRACE_GETREGS, pid, 0, &regs);
                if ((int)regs.orig_rax == 252)
                    break;
                if (!flip && (count > 2))
                {
                    printf("%s", syscalls_64_g[regs.orig_rax].name);
                    fflush(stdout);
                }
                if (flip && (count > 2))
                {
                    printf(" = %s%lx\n", regs.rax?"0x":"", (long)regs.rax);
                }
                ptrace(PTRACE_SYSCALL, pid, 0, 0);
                wait(&status);
                count++;
            }
        }
        printf(" = ?\n");
        return(0);
}
