#include "multithreading.h"
#include <stdarg.h>

static pthread_mutex_t mutex_print;

void begin (void) __attribute__((constructor));
void end (void) __attribute__((destructor));

/**
 * tprintf - prints string and displays id for thread
 * @format: string to print
 * Return: 0
*/
int tprintf(char const *format, ...)
{
	va_list args;
	pthread_t thread_num;

	va_start(args, format);

	if (!format)
	{
		printf("format string error");
		exit(EXIT_FAILURE);
	}

	if (pthread_mutex_lock(&mutex_print))
	{
		printf("mutex lock failed\n");
		exit(EXIT_FAILURE);
	}
	thread_num = pthread_self();

	printf("[%lu] ", thread_num);
	vprintf(format, args);

	if (pthread_mutex_unlock(&mutex_print))
	{
		printf("mutex unlock failed");
		exit(EXIT_FAILURE);
	}
	va_end(args);

	return (EXIT_SUCCESS);
}
