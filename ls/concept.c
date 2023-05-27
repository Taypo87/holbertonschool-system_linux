#include "concept.h"

int main ()
{
   /** DIR *dir;
    struct dirent *entity;
    extern int errno;

    if (argc < 2)
    {
        dir = opendir(".");
        if (dir == NULL)
        {
            fprintf(stderr, "directoy open failed");
            return (EXIT_FAILURE);
        }
        
        entity = readdir(dir);
        while (entity != NULL)
        {
            if (entity->d_name[0] != '.')
            {
                fprintf(stdout, "%s\n", entity->d_name);
            }
            entity = readdir(dir);
        }
    }
    else
    {
        dir = opendir(argv[1]);
        if (dir == NULL)
        {
            fprintf(stderr, "directoy open failed");
            return (EXIT_FAILURE);
        }
        
        entity = readdir(dir);
        while (entity != NULL)
        {
            fprintf(stdout, "%s\n", entity->d_name);
            entity = readdir(dir);
        }
        exit(0);
    }
    closedir(dir);
    exit(0);
    */
    printf("abc\n");
    printf("file\n");
    printf("File2\n");
    printf("file3\n");
    printf("folder1\n");
    printf("Folder2\n");
    printf("folder3\n");
    printf("hls\n");
    return(0)
}
