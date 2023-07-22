#include "signals.h"
/**
* trace_signal_sender - calls trace handler
* Return: 0 on success -1 on failure
*/
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = *trace_handler;

	if (sigaction(SIGQUIT, &sa, NULL) != 0)
		return (-1);
	
	return (0);
}
/**
* trace_handler - handles the SIGQUIT signal and displays pid of sender
* @sig: the signal
* @siginfo: siginfo t struct
* @context: context pointer
*/
void trace_handler(int sig, siginfo_t *siginfo, void *context)
{
	pid_t sender_pid = siginfo->si_pid;

	context = NULL;
	if (sig == SIGQUIT && context == NULL)
	{
		printf("SIGQUIT sent by %d\n", sender_pid);
	}
}
