#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 10

char* _getline(const int fd)
{
    static char* leftovers = NULL;
    static size_t leftovercount = 0;

    char buffer[READ_SIZE];
    ssize_t bytesread;
    size_t i, j;

    // Check if there are leftovers from previous read
    if (leftovers != NULL)
    {
        for (i = 0; i < leftovercount; i++)
        {
            if (leftovers[i] == '\n')
                break;
        }

        // If a newline is found in leftovers, extract the line
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
            // No newline found, save leftovers for next iteration
            char* temp = realloc(leftovers, (leftovercount + READ_SIZE) * sizeof(char));
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
        // Allocate memory for leftovers
        leftovers = malloc(READ_SIZE * sizeof(char));
        if (leftovers == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return (NULL);
        }
    }

    // Read from file and search for newline
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

                // Copy leftovers
                for (j = 0; j < leftovercount; j++)
                    line[j] = leftovers[j];

                // Copy current line
                for (j = 0; j < i; j++)
                    line[leftovercount + j] = buffer[j];

                line[leftovercount + i] = '\0';

                // Save remaining characters as leftovers
                leftovercount = bytesread - i - 1;
                for (j = 0; j < leftovercount; j++)
                    leftovers[j] = buffer[i + 1 + j];

                return (line);
            }
        }

        // No newline found, expand leftovers if necessary
        char* temp = realloc(leftovers, (leftovercount + bytesread) * sizeof(char));
        if (temp == NULL)
        {
            fprintf(stderr, "Error: Memory allocation failed\n");
            free(leftovers);
            return (NULL);
        }
        leftovers = temp;

        // Copy buffer to leftovers
        for (i = 0; i < bytesread; i++)
            leftovers[leftovercount + i] = buffer[i];

        leftovercount += bytesread;
    }

    // Reached end of file, free memory and return NULL
    free(leftovers);
    leftovers = NULL;
    return (NULL);
}
