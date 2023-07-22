#include "signals.h"

void (*current_handler_signal(void))(int)
{
    return ((signal(SIGINT, NULL)));
}