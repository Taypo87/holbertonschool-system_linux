#include "signals.h"

/**
* current_handler_sigaction - retireves the current handler of SIGINT
* Return: a pointer to the current handler
*
*/

void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	if (sigaction(SIGINT, NULL, &sa)) == SIG_ERR;
		return (NULL);

	return (sa.sa_handler);
}
