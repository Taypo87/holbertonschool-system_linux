#include "concept.h"

int main(int argc, char *argv[])
{
    struct myFile *fileList;
	char *targets[16] = {NULL};
	int x = 0, i = 0, flag = 0, check = 0;

    if (argc == 1)
    {
        targets[0] = ".";
        i = 1;
    }
    for (x = 1; x < argc; x++)
    {
        if (argv[x][0] != '-')
        {
            check = checkArg(argv[x], argv);
            if (check == -1)
                flag = 1;
            if (check == 1)
            {
                targets[i] = argv[x];
                i++;
            }
        }
    }
    if (check == 0)
        printf("\n");
    for (x = 0; x < i; x++)
    {
        if (targets[x])
        {
            if (i > 1 || flag == 1)
                printf("%s:\n", targets[x]);

            fileList = direntLoad(targets[x]);
		    statLoad(fileList, targets[x]);
		    sortStruct(fileList, targets[x]);
            printList(fileList, targets[x]);
            freeStructMembers(fileList, targets[x]);
            free(fileList);
            printf("\n");
        }
    }
    return (0);
}
