#include "signals.h"
/**
* main - main function sends a signal to a given pid
* @argc: number of arguments
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	int pid;
	pid_t proccess_id;

	if (argc != 2)
	{
		printf("Usage: %s <pid>", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	proccess_id = pid;
	if (kill(proccess_id, SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
