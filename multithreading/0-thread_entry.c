#include "multithreading.h"

/**
 * thread_entry - creates entry point for thread
 * @arg: argument to print
 * Return: None
*/
void *thread_entry(void *arg)
{
    printf("%s\n", (char *)arg);
	pthread_exit(NULL);
	return (0);
}
