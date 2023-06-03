#include "concept.h"
/**
* checkArg - checks a given argment for exists, is file or folder
* returns 0 for file, 1 for folder, -1 if does not exist
*/

int checkArg(char *target)
{
    char file_path[PATH_MAX + 1];
    int exists = 0;
    struct stat *file_stat;

    exists = lstat(target, file_stat);
    if (exists == -1)
        return (-1);
    else
    {
        if (S_ISREG(file_stat->st_mode))
            return (0);
        if (S_ISDIR(file_stat->st_mode))
            return (1);
    }
    return(-1);
}
