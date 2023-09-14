#include "list.h"
#include "multithreading.h"

list_t *prime_factors(char const *s)
{
    unsigned long num = atoi(s), prime = 2, i;

    {
    for (i = 2; i <= num; i++)
    {
        while (num % i == 0 && isPrime(i))
        {
            printf("%d ", (int)i);
            num /= i;
        }
    }
    return(0);
}
    

}

int prime_check(unsigned long num)
{
    unsigned long i;

    if (num <= 1)
    {
        return (0);
    }
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return (0);
        }
    }
    return (1); 
}