#include "concept.h"

const char *formatPerms(int permission)
{
    switch (permission)
    {
        case 0:
            return ("---");
        case 1:
            return ("--x");
        case 2:
            return ("-w-");
        case 3:
            return ("-wx");
        case 4:
            return ("r--");
        case 5:
            return ("r-x");
        case 6:
            return ("rw-");
        case 7:
            return ("rwx");
        default:
            return "???";
    }
}