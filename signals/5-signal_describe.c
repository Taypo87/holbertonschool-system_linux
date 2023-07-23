#include "signals.h"

int main(int argc, char **argv)
{
    int number;

    if (argc != 2)
        {
            printf("Usage: %s <signum>", argv[0]);
            exit(EXIT_FAILURE);
        }
    number = atoi(argv[1]);
    if (number > 0 && number < NSIG)
        printf("%i: %s\n", number, sys_siglist[number]);
    else
        printf("%i: Unknown signal %i\n", number, number);
    return (EXIT_SUCCESS);
}
