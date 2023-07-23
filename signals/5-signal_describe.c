#include "signals.h"
/**
* main - checks if signal number is in range and prints corresponding signal
* @argc: the argument count
* @argv: the argument array
* Return: EXIT_FAILURE EXIT _SUCCESS
*/
int main(int argc, char **argv)
{
	int number;

	if (argc != 2)
	{
		printf("Usage: %s <signum>", argv[0]);
		exit(EXIT_FAILURE);
	}
	number = atoi(argv[1]);
	if (number > 0 && number < NSIG)
		printf("%i: %s\n", number, sys_siglist[number]);
	else
		printf("%i: Unknown signal %i\n", number, number);
	return (EXIT_SUCCESS);
}
