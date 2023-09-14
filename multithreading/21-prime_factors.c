#include "list.h"
#include "multithreading.h"

list_t *prime_factors(char const *s)
{
    list_t *list;
    unsigned long num = strtoul(s, NULL, 10), prime = 2, i, *templong;
    // use strtoul instead of atoi
    list = malloc(sizeof(list_t));
    
    list_init(list);
    for (i = 2; i <= num; i++)
    {
        while (num % i == 0 && prime_check(i))
        {
            templong = malloc(sizeof(unsigned long));
            *templong = i;
            list_add(list, templong);
            num /= i;
        }
    }
    if (num > 2)
        list_add(list, (void*)num);
    return(list);

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
