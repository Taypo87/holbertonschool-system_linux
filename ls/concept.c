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
	int i = 0;
	size_t list_size = 0;

	if (argc == 1)
	{
		target = ".";
		list_size = list_length(target);
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
/**
* get a list of d_name, sort and print
*/ 
/**
	}
	else
	{
		va_list args;
		//va_start(args, argc);

		for (i = 1; i < argc; i++)
		{	
			if (argv[i][0] != '-')
			{
				target = (argv[i]);
				entry = loadStruct(target);
			}
/**	
*		// if argv[1][0] != '-' then its a directory name, modify above code
*		// we'll have to check for multiple arguments and directories!!! wtf
*/
//		}
	}
	
	return(0);
}
