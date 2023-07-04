#include "header.h"

static int is_32;
static int is_msb;
/**
 * printelfh - prints elf header
 * @fp: pointer to file stream
 * @arg_str: string containing name of program
 *
 * Return: 0 on success, otherwise 1
 */
int printelfh(FILE *fp, char *arg_str)
{
	header_info hdr;
	int exit_stat;

	fread(&hdr.Ehdr64, sizeof(hdr.Ehdr64), 1, fp);
	rewind(fp);
	fread(&hdr.Ehdr32, sizeof(hdr.Ehdr32), 1, fp);
	if (memcmp(hdr.Ehdr64.e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, "%s: %s%s\n", arg_str,
				"Error: Not an ELF file - ",
				"it has the wrong magic bytes at the start");
		exit_stat = 1;
		goto out;
	}
	puts("ELF Header:");
	printmag(hdr);
	exit_stat = printclass(hdr, arg_str);
	if (exit_stat)
		goto out;
	exit_stat = printdata(hdr, arg_str);
	if (exit_stat)
		goto out;
	exit_stat = printversion(hdr, arg_str);
	if (exit_stat)
		goto out;
	printelfhwrapper(hdr);
	exit_stat = 0;
out:
	fclose(fp);
	if (exit_stat)
		return (1);
	return (0);
}


/**
* print_task_0_wrapper - wrapper for print functions
* @headers: struct containing elf data structs
*/
print_task_0_wrapper(header_info headers)
{
   
    printosabi(headers);
	printtype(headers, is_msb);
	printmachine(headers, is_msb);
	printfileversion(headers, is_msb);
	printentry(headers, is_32, is_msb);
	printpshoff(headers, is_32, is_msb);
	printflags(headers, is_32, is_msb);
	printhdrsize(headers, is_32, is_msb);
	printphnum(headers, is_32, is_msb);
	printshentsize(headers, is_32, is_msb);
	printshnum(headers, is_32, is_msb);
	printshstrndx(headers, is_32, is_msb);

}
/**
* print_magic - prints the magic field
* @headers: struct containing elf data structs 
* Return: 0 on success, anyhting else error
*/
print_magic(header_info headers)
{
    size_t i;
    
    printf("%11s", "Magic:     ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", headers.Ehdr64.e_ident[i]);
    putchar('\n');
}
/**
* print_class - prints the class field
* @headers: struct containing elf data structs 
* Return: 0 on success, anyhting else error
*/
int print_class(header_info headers, char *program)
{
	if (hdr.Ehdr64.e_ident[EI_CLASS] == ELFCLASSNONE)
	{
		fprintf(stderr, "%s: Error: Invalid class\n", arg_str);
		return (1);
	}
	if (hdr.Ehdr64.e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%7s%-30c%s\n", "Class", ':', "ELF32");
		is_32 = 1;
	}
	else
	{
		printf("%7s%-30c%s\n", "Class", ':', "ELF64");

	}
	return (0);
}
/*
* print_data - prints the data field
* @headers: struct containing elf data structs 
* Return: 0 on success, anyhting else error
*/
int print_data(header_info headers, char* program)
{

	if (headers.Ehdr64.e_ident[EI_DATA] == ELFDATANONE)
	{
		fprintf(stderr, "%s: Error: Invalid data encoding\n", program);
		return (1);
	}
	if (headers.Ehdr64.e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("%6s%-31c%s%s\n", "Data", ':', "2's complement, ",
				"little endian");
	}
	else
	{
		printf("%6s%-31c%s%s\n", "Data", ':', "2's complement, ",
				"big endian");
	}
	return (0);
}