#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 10


char *_getline(const int fd);


#endif