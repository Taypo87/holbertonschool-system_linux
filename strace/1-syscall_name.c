#include "syscall_header.h"
#include "syscalls.h"

int main(int argc, char** argv)
{
    pid_t pid;
    int status, flip, writeflag = 0;
    struct user_regs_struct regs;
    char* write = "write";

    if (check_arg(argc, argv) == 1)
        exit(EXIT_FAILURE);
    setbuf(stdout, NULL);

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
        for (flip = 0; !WIFEXITED(status); flip ^= 1)
        {
            writeflag = 0;
            waitpid(pid, &status, 0);
            ptrace(PTRACE_GETREGS, pid, 0, &regs);
            if (flip)
                printf("%s", syscalls_64_g[regs.orig_rax].name);
            if (strcmp(syscalls_64_g[regs.orig_rax].name, write) != 0 && flip)
                printf("\n");
            else
                writeflag = 1;
            ptrace(PTRACE_SYSCALL, pid, 0, 0);
            if (writeflag == 1 && flip)
                printf("\n");
        }
    }
    return(0);
}
