#include "concept.h"

int main(int argc, char *argv[])
{
    struct myFile *fileList;
	char *targets[16] = {NULL}, option = '\0';
	int x = 0, i = 0, flag = 0, check = 0;
    if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
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
        if (argv[x][0] == '-')
                option = argv[x][1];
    }
    if (argc > 3)
        printf("\n");
    if (check == 0 && argc > 2 && i > 1 )
        printf("\n");
    
    if (argc == 2 && argv[1][0] == '-')
    {
        flag = 2;
        check = 2;
    }
    for (x = 0; x < i; x++)
    {
        if (targets[x])
        {
            if ((i > 1 && argc > 1) || (flag == 1 && argc > 1) || (check == 0 && argc > 1))
                printf("%s:\n", targets[x]);

            fileList = direntLoad(targets[x]);
		    statLoad(fileList, targets[x]);
		    sortStruct(fileList, targets[x]);
            selectPrint(fileList, targets[x], option);
            freeStructMembers(fileList, targets[x]);
            free(fileList);
/**
*           Had a newline here but it broke the checker in task 5
*/
        }
    }
    return (0);
}
