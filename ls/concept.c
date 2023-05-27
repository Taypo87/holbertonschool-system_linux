#include "concept.h"

int main (int argc, char **argv)
{
    DIR *dir;
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
                printf("%s\n", entity->d_name);
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
            printf("%s\n", entity->d_name);
            entity = readdir(dir);
        }
        return(0);
    }
    closedir(dir);
    
    return(0);
}
