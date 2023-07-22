#include "signals.h"

void (*current_handler_signal(void))(int)
{
    void (*handler)(int) = signal(SIGINT, SIG_DFL);
    
    return ((signal(SIGINT, handler)));
}