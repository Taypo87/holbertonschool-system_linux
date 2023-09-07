#include "syscall_header.h"
#include "syscalls.h"

int check_arg(int argc, char** argv)
{
    struct stat sb;

    if (argc < 2)
    {
        fprintf(stderr, "%s command [args...]\n", argv[1]);
        return(1);
    }

    if (stat(argv[1], &sb) == -1)
    {
        fprintf(stderr, "%s: Can't stat '%s': No such file or directory\n",
                            *argv, argv[1]);
        return(1);
    }
    return(0);
}
