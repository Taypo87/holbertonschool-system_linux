#include "signals.h"
/**
* main - sets sig handler and pauses for signal
* @void: voided
* Return: 0 on success
*/
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_sigint_once;
	sigaction(SIGINT, &sa, NULL);
	pause();
	printf("Signal received\n");
	return (0);
}
/**
* handle_sigint_once - signal handler for task 6
* @sig: the signal
*/
void handle_sigint_once(int sig)
{
	printf("Caught %i\n", sig);
}
