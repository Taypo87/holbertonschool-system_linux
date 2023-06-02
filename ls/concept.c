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
	size_t i = 0;
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

	}
	else
	{

		for (x = 1; x < argc; x++)
		{	
			if (argv[x][0] != '-')
			{
				target = (argv[x]);
				
			}
/**	
*		// if argv[1][0] != '-' then its a directory name, modify above code
*		// we'll have to check for multiple arguments and directories!!! wtf
*/
		}
	}
	
	return(0);
}
