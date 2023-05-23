#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 10

char* _getline(const int fd)
{
    static char* leftovers = NULL;
    static size_t leftovercount = 0;
    char* temp;

    char buffer[READ_SIZE];
    size_t bytesread;
    size_t i, j;

    if (leftovers != NULL)
    {
        for (i = 0; i < leftovercount; i++)
        {
            if (leftovers[i] == '\n')
                break;
        }

        if (i < leftovercount)
        {
            char* line = malloc((i + 1) * sizeof(char));
            for (j = 0; j < i; j++)
                line[j] = leftovers[j];
            line[i] = '\0';

            leftovercount -= i + 1;
            for (j = 0; j < leftovercount; j++)
                leftovers[j] = leftovers[i + 1 + j];

            return (line);
        }
        else
        {
            temp = realloc(leftovers, (leftovercount + READ_SIZE) * sizeof(char));
            if (temp == NULL)
            {
                fprintf(stderr, "Error: Memory allocation failed\n");
                free(leftovers);
                return NULL;
            }
            leftovers = temp;
        }
    }
    else
    {
        leftovers = malloc(READ_SIZE * sizeof(char));
        if (leftovers == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return (NULL);
        }
    }

    while ((bytesread = read(fd, buffer, READ_SIZE)) > 0)
    {
        for (i = 0; i < bytesread; i++)
        {
            if (buffer[i] == '\n')
            {
                char* line = malloc((leftovercount + i + 1) * sizeof(char));
                if (line == NULL)
                {
                    fprintf(stderr, "Error: Memory allocation failed\n");
                    free(leftovers);
                    return (NULL);
                }

                for (j = 0; j < leftovercount; j++)
                    line[j] = leftovers[j];

                for (j = 0; j < i; j++)
                    line[leftovercount + j] = buffer[j];

                line[leftovercount + i] = '\0';

                leftovercount = bytesread - i - 1;
                for (j = 0; j < leftovercount; j++)
                    leftovers[j] = buffer[i + 1 + j];

                return (line);
            }
        }

        char* temp = realloc(leftovers, (leftovercount + bytesread) * sizeof(char));
        if (temp == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed\n");
            free(leftovers);
            return (NULL);
        }
        leftovers = temp;

        for (i = 0; i < bytesread; i++)
            leftovers[leftovercount + i] = buffer[i];

        leftovercount += bytesread;
    }

    free(leftovers);
    leftovers = NULL;
    return (NULL);
}
