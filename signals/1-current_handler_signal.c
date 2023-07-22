#include "signals.h"

void (*current_handler_signal(void))(int)
{
    void (*func)(int) = signal(SIGINT, SIG_DFL);
    
    signal(SIGINT, func);
    return (func);
}
