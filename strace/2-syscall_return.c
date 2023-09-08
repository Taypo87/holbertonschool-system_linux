#include "syscall_header.h"
#include "syscalls.h"

int main(int argc, char** argv)
{
        pid_t pid;
        int status, flip, writeflag;
        struct user_regs_struct regs;
        char* write = "write";

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
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            for (flip = 1; !WIFEXITED(status); flip ^= 1)
            {

                
                waitpid(pid, &status, 0);
                memset(&regs, 0, sizeof(regs));
                ptrace(PTRACE_GETREGS, pid, 0, &regs);
                if (writeflag == 1 && flip)
                    printf("\n");
                writeflag = 0;
                if (flip & !WIFEXITED(status))
                {
                    if (writeflag == 1)
                        printf("\n = %lx\n", (long)regs.rax);
                    writeflag = 0;
                    printf("%s", syscalls_64_g[regs.orig_rax].name);
                    if (strcmp(syscalls_64_g[regs.orig_rax].name, write) != 0)
                        printf(" = %lx\n", (long)regs.rax);
                    else
                        writeflag = 1;
                }
                ptrace(PTRACE_SYSCALL, pid, 0, 0);
            }
        }
        printf("exit_group = ?\n");
        return(0);
}
