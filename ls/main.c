#include "concept.h"

int main(int argc, char *argv[])
{
    struct myFile *fileList;
	char *targets[16] = {NULL};
	int x = 0, i = 0;

    if (argc == 1)
        targets[0] = ".";
    for (x = 1; x < argc; x++)
    {
        if (argv[x][0] != '-')
        {
            if(checkArg(argv[x]) == 1)
            {
                targets[i] = argv[x];
                i++;
            }
        }
    }
    for (x = 0; x < i; x++)
    {
        if (targets[x])
        {
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
