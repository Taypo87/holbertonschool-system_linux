#include "signals.h"
/**
* main - main function sends a signal to a given pid
* @argc: number of arguments
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(argv[1], SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
