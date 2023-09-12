#include "multithreading.h"

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
