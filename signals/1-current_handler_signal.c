#include "signals.h"

void (*current_handler_signal(void))(int)
{
    void *handler;

    handler = (signal(SIGINT, NULL));

    return(handler);
}