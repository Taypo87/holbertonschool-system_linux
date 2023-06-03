#include "concept.h"

int main(int argc, char *argv[])
{
    struct myFile *fileList;
	char *targets[16], *option;
	int x = 1, i =0;

    targets[0] = ".";
    for (x = 1; x < argc; x++)
    {
        if (argv[x][0] != '-')
            targets[i] = argv[x];
        else
            option = argv[x];
    }

    for (i = 0; i < x; i++)
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