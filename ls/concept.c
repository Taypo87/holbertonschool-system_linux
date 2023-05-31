#include "concept.h"
/**
* main - main function in the program, dictates flow and function call
* @argc: number of arguments passed to the program
* @argv: array containing the arguments passed 
* Return: 0
*/
int main (int argc, char *argv[])
{
	struct myFile *entry;
	char *target;
	int i = 0;

	if (argc == 1)
	{
		target = ".";
		entry = loadStruct(target);
		sortStruct(entry);
		while(entry[i].fileName[0] != '\0')
		{
			if (entry[i].fileName[0] != '.')
			{
			printf("%s\n", entry[i].fileName);
			}
			i++;
		}
		free(entry);
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
