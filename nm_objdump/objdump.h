#ifndef objdump_h
#define objdump_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>


#ifndef STT_REL
#define STT_REL 9
#endif



int parse_args(int argc, char **argv);
void nm_wrapper(int fd);
void handleSymbolType(int symbolType);


#endif