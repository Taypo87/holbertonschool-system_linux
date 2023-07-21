#include "signals.h"

int handle_signal(void)
/*
* handle_signal - catches the signal and calls handle_sigint
* Return: -1 on error 0 on success
*/
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
/*
* handle_signal - catches the signal and calls handle_sigint
* @sig: signal
*/
void handle_sigint(int sig)
{
    printf("Gotcha! [%i]\n", sig);
}
