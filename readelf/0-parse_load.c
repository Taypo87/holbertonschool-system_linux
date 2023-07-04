#include "header.h"

int check_args(int argc, char** argv)
{
    struct stat sb;

    if (argc != 2)
    {
        fprintf(stderr, "%s: Warning: Nothing to do.\n"
				"Usage: %s elf-file\n", *argv, *argv);
        return (1);
    }
    stat(argv[1], &sb);
    if (!S_ISREG(sb.st_mode))
    {
        fprintf(stderr, "%s: Error: '%s': is not an ordinary file\n",
				argv[0], argv[1]);
        return (1);
    }
    return (0);

}


/**
* load_struct - loads elf structs for easy access
* @headers: struct being populated
* @elf_file: file being read from
* Return: 0 on success, anything else error
*/
int load_struct(header_info *headers, FILE *elf_file)
{
    fread(&headers->Ehdr64, sizeof(headers->Ehdr64), 1, elf_file);
    if (headers->Ehdr64.e_ident[EI_CLASS] == ELFCLASS32)
    {
        fseek(elf_file, 0, SEEK_SET);
        fread(&headers->Ehdr32, sizeof(headers->Ehdr32), 1, elf_file);
    }
    else if (headers->Ehdr64.e_ident[EI_CLASS] == ELFCLASS64)
    {
        fseek(elf_file, 0, SEEK_SET);
        fread(&headers->Ehdr64, sizeof(headers->Ehdr64), 1, elf_file);
    }
    else
    {
        printf("Invalid ELF class.\n");
        return (1);
    }
    return (0);
}
