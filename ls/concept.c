#include "concept.h"
/**
* main - main function in the program, dictates flow and function call
* @argc: number of arguments passed to the program
* @argv: array containing the arguments passed
* Return: 0
*/
int main (int argc, char *argv[])
{
	struct myFile *fileList;
	char *target;
	int x = 0;
	size_t list_size = 0, i= 0;

	if (argc == 1)
	{
		target = ".";
		list_size = listLength(target);
		fileList = direntLoad(target);
		statLoad(fileList, target);
		sortStruct(fileList, target);
		while(i < list_size)
		{
			if (fileList[i].fileName[0] != '.')
			{
			printf("%s\n", fileList[i].fileName);
			}
			i++;
		}
		freeStructMembers(fileList, target);
		free(fileList);
	}
	else
	{
		for (x = 1; x < argc; x++)
		{
			if (argv[x][0] != '-')
			{
				target = (argv[x]);
			}
		}
	}
	return (0);
}
