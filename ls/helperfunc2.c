#include "concept.h"
/**
* checkArg - checks a given argment for exists, is file or folder
* returns 0 for file, 1 for folder, -1 if does not exist
*/

int checkArg(char *target, char **argv)
{
    struct stat file_stat;

    if (lstat(target, &file_stat) == -1)
    {
        fprintf(stderr, "%s: cannot access %s: No such file or directory\n",argv[0] ,target);
        return (-1);
    }
    if (S_ISREG(file_stat.st_mode))
    {
        printf("%s\n", target);
        return (0);
    }
    if (S_ISDIR(file_stat.st_mode))
    {
        if ((file_stat.st_mode & S_IRUSR) == 0 || (file_stat.st_mode & S_IXUSR) == 0)
        {
            fprintf(stderr, "%s: cannot open directory %s: Permission denied\n",argv[0] ,target);
            return (-1);
        }
        return (1);
    }
    

    return(-1);
}

void selectPrint(struct myFile *fileList, char *target, char option)
{
    if (option == '\0' || option == '1')
        printList(fileList, target);

    if (option == 'a')
        printLista(fileList, target);
    
    if (option == 'A')
        printListA(fileList, target);
    
    if (option == 'l')
        printListl(fileList, target);
}

void printLista(struct myFile *fileList, char *target)
{
    size_t i = 0;

    while (i < listLength(target))
    {
        printf("%s\n", fileList[i].fileName);
        i++;
    }
}

void printListA(struct myFile *fileList, char *target)
{
    size_t i = 2;

    while (i < listLength(target))
    {
        printf("%s\n", fileList[i].fileName);
        i++;
    }
}

void printListl(struct myFile *fileList, char *target)
{
    size_t i = 0;

    while (i < listLength(target))
    {
        if (fileList[i].fileName[0] != '.')
        { 
            printf("%s\n", fileList[i].fileName);
        }
        i++;
    }
}

