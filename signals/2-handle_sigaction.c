#include "signals.h"
/**
* handle_sigaction - catches the signal and calls sigaction_handler
* Return: -1 on error 0 on success
*/
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = sigaction_handler;

	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);

	return (0);
}
/**
* sigaction_handler - handles sigint
* @sig: signal
*/
void sigaction_handler(int sig)
{
	printf("Gotcha! [%i]\n", sig);
	fflush(stdout);
}
