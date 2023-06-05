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
char *itoa(int value)
{
    static char buffer[12];
    int i = 10;

    buffer[11] = '\0'; 

    if (value < 0)
    {
        buffer[0] = '-';
        value = -value;
    }
    else if (value == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }

    while (value > 0)
    {
        buffer[i] = '0' + (value % 10);
        value /= 10;
        i--;
    }

    return &buffer[i + 1];
}
void removeNewline(char *timeString)
{
    int i = 0;
    while (timeString[i] != '\0')
    {
        if (timeString[i] == '\n')
        {
            timeString[i] = '\0';
        }
        i++;
    }
}