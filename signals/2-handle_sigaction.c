#include "signals.h"

int handle_sigaction(void)
{
    struct sigaction sa;

    sa.sa_handler = sigaction_handler;

    sigaction(SIGINT, &sa, NULL);
}

void sigaction_handler(int sig)
{
    printf("Gotcha! [%i]\n", sig);
    fflush(stdout);
}