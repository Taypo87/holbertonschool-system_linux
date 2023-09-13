#include "multithreading.h"

pthread_mutex_t lock;
void begin (void) __attribute__((constructor));
void end (void) __attribute__((destructor));

/**
 * tprintf - prints string and displays id for thread
 * @format: string to print
 * Return: 0
*/
int tprintf(char const *format, ...)
{
	pthread_t id = pthread_self();

	printf("[%lu] %s", id, format);
	return (0);
}
void begin(void)
{
	pthread_mutex_init(&lock, NULL);
}

void end(void)
{
	pthread_mutex_destroy(&lock);
}
