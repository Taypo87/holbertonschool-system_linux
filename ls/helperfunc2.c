#include "concept.h"
/**
* checkArg - checks a given argment for exists, is file or folder
* returns 0 for file, 1 for folder, -1 if does not exist
*/

int checkArg(char *target)
{
    struct stat file_stat;

    if (lstat(target, &file_stat) == -1)
        return (-1);
    if (S_ISREG(file_stat.st_mode))
    {
        printf("%s\n", target);
        return (0);
    }
    if (S_ISDIR(file_stat.st_mode))
        return (1);
    
    return(-1);
}
