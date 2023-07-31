#ifndef objdump_h
#define objdump_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>


int parse_args(int argc, char **argv);
void nm_wrapper(int fd);


#endif