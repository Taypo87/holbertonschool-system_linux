#ifndef _THREADHEAD_
#define _THREADHEAD_

#include <pthreads.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void blur_portion(blur_portion_t const *portion);
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel);
list_t *prime_factors(char const *s);




#endif