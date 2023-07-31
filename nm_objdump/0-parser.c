#include "objdump.h"


int parse_args(int argc, char **argv)
{
    int fd;
    int i;
    struct stat st;

    if (argc == 1)
    {
        fd = open("a.out", O_RDONLY);
        printf("break 10");
        if (!fd)
        {
            printf("%s: 'a.out': No such file\n", argv[0]);
            return (0);
        }
        else 
            nm_wrapper(fd);
    }
    if (argc > 1) 
    {
        for (i = 1; i < argc; i++)
        {
            printf("this should print");
            fd = open(argv[i], O_RDONLY);
            printf("break 11");
            if (!fd)
            {
                printf("%s: '%s': No such file\n", argv[0], argv[i]);
            }
            else
            {
                if (stat(argv[i], &st) == 0 && st.st_mode & S_IXUSR)
                {
                    printf("break 12");
                    nm_wrapper(fd);
                }
                else
                    printf("%s: %s: File format not recognized\n", argv[0], argv[1]);
            }
            close(fd);
        }
    }
    return (0);
}