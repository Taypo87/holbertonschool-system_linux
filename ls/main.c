#include "concept.h"

int main(int argc, char *argv[])
{
    struct myFile *fileList;
	char *targets[16];
	int x = 1, i = 0;

    if (argc = 1)
        targets[0] = ".";
    for (x = 1; x < argc; x++)
    {
        if (argv[x][0] != '-')
        {
            if(checkArg(argv[x]) == 1)
                targets[i] = argv[x];
            if(checkArg(argv[x]) == 0)
                printf("%s\n", argv[x]);
        }
    }

    for (i = 0; i < x - 1; i++)
    {
        fileList = direntLoad(targets[i]);
		statLoad(fileList, targets[i]);
		sortStruct(fileList, targets[i]);
        printList(fileList, targets[i]);
        freeStructMembers(fileList, targets[i]);
        free(fileList);
    }
    return (0);
}
