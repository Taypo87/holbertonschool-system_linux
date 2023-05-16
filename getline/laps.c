#include "laps.h"

void race_state(int *id, size_t size)
{
    static int started[5];
    static int lap = 0;
    static int cars = 0;
    int hasstarted = 0;

    for (int i = 0; i < size; i++)
    {
        int arrlen = sizeof started / sizeof started[0];
        printf("%d\n", arrlen);
        for (int x = 0; x < arrlen; x++)
        {
            //printf("%ls", started);
            if (started[x] == id[i])
            {
                hasstarted = 1;
                break;
            }
        }
        //printf("%ls", started);
        if (hasstarted != 1)
        {
            //printf("%i", id[i]);
            started[arrlen - i - 1] = id[i];
            //printf("%i", started[arrlen - 1]);
          //  printf("Car %d has joined the race\n", id[i]);
        }
    }
}