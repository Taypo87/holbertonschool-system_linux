#include "signals.h"

int handle_signal(void)
{
    if (signal(SIGINT, handle_sigint) == SIG_ERR)
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}

void handle_sigint(int sig)
{
    printf("Gotcha! [%i]", sig);
}