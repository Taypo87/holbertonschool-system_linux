#include "signals.h"

void (*current_handler_signal(void))(int)
{
    if (signal(SIGINT, SIG_DFL) == SIG_ERR)
        return NULL;
    
    return ((signal(SIGINT, SIG_DFL)));
}
