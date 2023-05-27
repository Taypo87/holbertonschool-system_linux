#include "concept.h"

int main (int argc, char **argv)
{
    DIR *dir;
    struct dirent *entity;

    if (argc < 2)
    {
        dir = opendir(".");
        if (dir == NULL)
        {
            printf("directoy open failed");
            return (1);
        }
        
        entity = readdir(dir);
        while (entity != NULL)
        {
            printf("%s\n", entity->d_name);
            entity = readdir(dir);
        }
    }
    else
    {
        dir = opendir(argv[1]);
        if (dir == NULL)
        {
            printf("directoy open failed");
            return (1);
        }
        
        entity = readdir(dir);
        while (entity != NULL)
        {
            printf("%s\n", entity->d_name);
            entity = readdir(dir);
        }
        return(1);
    }
}