#ifndef _HEADER_H
#define _HEADER_H

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <libelf.h>
#include <gelf.h>
#include <sys/stat.h>


/**
 * struct header_info - struct containing 32 and 64 bit ELF header information
 * @Ehdr32: 32-bit ELF header
 * @Ehdr64: 64-bit ELF header
 * @Shdr32: 32-bit ELF section header
 * @Shdr64: 64-bit ELF section header
 */
typedef struct header_info
{
    Elf32_Ehdr Ehdr32;
    Elf64_Ehdr Ehdr64;
    Elf32_Shdr Shdr32;
    Elf54_Shdr Shdr64;
} header_info;


/* 0-parse_load.c */
int check_args(int argc, char** argv);
int load_struct(header_info *headers, FILE *elf_file);

/* 0-elf_hdrs.c */
print_task_0(header_info headers, char *program);
print_magic(header_info headers);
int print_class(header_info headers, char *program);
int print_data(header_info headers, char* program);

#endif