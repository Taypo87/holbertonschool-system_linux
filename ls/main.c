#include "concept.h"

// first check for no args being passed ie argc = 1
// otherwise take all the arguemnts and store them in an array if they aren't options. if they are we'll handle those in a different manner

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
// we'll have to do some option handling, switch case for the print function being used?
    for (i = 0; i < x; i++)
    {
        fileList = direntLoad(targets[i]);
		statLoad(fileList, targets[i]);
		sortStruct(fileList, targets[i]);
        printList(fileList, targets[i]);
        freeStructMembers(fileList, targets[i]);
        free(fileList);
    }
}