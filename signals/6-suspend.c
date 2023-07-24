#include "singals.h"

int main()
{
	struct sigaction sa;

	sa.sa_handler = handle_sigint
	pause();
	return (0);
}
/**
* handle_sigint_once - signal handler for task 6
* @sig: the signal
*/
void handle_sigint_once(int sig);
{
	printf("Caught %i\n", sig);
}
