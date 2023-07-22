#include "signals.h"

/**
* current_handler_sigaction - retireves the current handler of SIGINT
* Return: a pointer to the current handler 
*
*/

void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	return(sigaction(SIGINT, NULL, &sa));
}
