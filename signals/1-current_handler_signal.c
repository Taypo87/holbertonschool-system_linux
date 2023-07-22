#include "signals.h"

/**
* current_handler_signal - retireves the current handler for SIGINT
* Return: pointer to the current handler
*
*/
void (*current_handler_signal(void))(int)
{
	void (*func)(int) = signal(SIGINT, SIG_DFL);

	signal(SIGINT, func);
	return (func);
}
