#include "syscall_header.h"
#include "syscalls.h"

int main(int argc, char** argv)
{
        pid_t pid;
        int status;
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
            ptrace(PTRACE_ATTACH, pid, NULL, NULL);
            waitpid(pid, &status, 0);
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            while (1)
            {
                waitpid(pid, &status, 0);
                ptrace(PTRACE_GETREGS, pid, 0, &regs);
                if (WIFEXITED(status))
                    break;
                printf("%lu\n", (long)regs.orig_rax);
                ptrace(PTRACE_SYSCALL, pid, 0, 0);
            }
            ptrace(PTRACE_DETACH, pid, NULL, NULL);
        }
        return(0);
}

