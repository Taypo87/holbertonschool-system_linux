#include "signals.h"

void (*current_handler_signal(void))(int)
{
    void (*handler)(int) = signal(SIGINT, SIG_DFL);
    if (signal(SIGINT, SIG_DFL) == SIG_ERR)
        return NULL;
    
    return ((signal(SIGINT, NULL)));
}
