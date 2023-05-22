#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 10

char* _getline(const int fd)
{
    static int readcount = 0;
    static int x = 0;
    static char *leftovers = NULL;
    char* buffer;
    static char* fullline = NULL;
    ssize_t bytesread;
    static size_t i;
    static size_t linesize = 0;
    static size_t totalsize = READ_SIZE;
    static char* newfullline = NULL;
    

    if (leftovers != NULL)
    {
        buffer = malloc(READ_SIZE * sizeof(char));
        bytesread = read(fd, buffer, READ_SIZE);
        i = 0;
        while (i < bytesread)
        {

        }
    }





    if (newfullline != NULL)
    {
        buffer = malloc(READ_SIZE * sizeof(char));
        bytesread = read(fd, buffer, READ_SIZE);
        leftovers = malloc(READ_SIZE * sizeof(char))
        i = 0;
        while (i < bytesread)
        {
            if (buffer[i] == '\n')
            {
                newfullline[x] = '\0';
                x = 0;
                while (i < bytesread)
                {
                    leftovers[x] = buffer[i];
                    x++;
                    i++;
                }
                return (newfullline);
            }
            newfullline[x] = buffer[i]
        }
    }
    if (leftovers == NULL && newfullline == NULL)
    {
        leftovers = malloc(READ_SIZE * sizeof(char));
        buffer = malloc(READ_SIZE * sizeof(char));
        bytesread = read(fd, buffer, READ_SIZE);
        for (i = 0; i < bytesread; i++)
        {
            if(buffer[i] == '\n')
            {
                fullline[x] = '\0';
                x = 0;
                while (i < bytesread)
                {
                    leftovers[x] = buffer[i];
                    x++;
                    i++;
                }
                x = 0;
                return (fullline);
            }
            else
            {
                fullline[x] = buffer[i];
                x++;
            }           
        }
        totalsize += READ_SIZE;
        newfullline = realloc(fullline, totalsize * sizeof(char));
        free(buffer);
        _getline(fd);
    }
}