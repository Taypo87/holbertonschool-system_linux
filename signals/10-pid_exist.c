#include <signal.h>
#include <stdlib.h>
/**
* main - checks if a process exists for a given pid
* @argc: argument count
* @argv: argument vector
* Return: 1 if process exists, 0 otherwise
*/
int main(int argc, char **argv)
{
	return (kill(atoi(argv[argc - 1]), 0));
}
