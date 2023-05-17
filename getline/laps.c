#include "laps.h"

void race_state(int *id, size_t size)
{
    static int started[10];
    static int lap = 0;
    static int cars = 0;
    static int inrace = 0;
    int hasstarted = 0;

    for (int i = 0; i < size; i++)
    {
        int arrlen = 10;
        //printf("%d\n", arrlen);
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
            //printf("%i\n", id[i]);
            started[(arrlen - size - i - 1)] = id[i];

            //printf("%i\n", started[(arrlen - size - i - 1)]);
          printf("Car %d has joined the race\n", started[(arrlen - size - i - 1)]);
        }
    }
   /* int y = 0;
    while (y < 10)
    {
        printf("%i\n", started[y]);
        y++;
    }
    */
}