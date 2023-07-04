#include "header.h"

int main(int argc, char **argv)
{
    FILE *elf_file;
    header_info headers;
    //check args before opening, return 0 on good, 1 if not and exit prgram

    if (check_args(argc argv) == 1)
        return (1);
    elf_file = fopen(argv[1], "r");
    if (!elf_file)
    {
        fprintf(stderr, "%s: Error: '%s': No such file\n", argv[0], argv[1]);
        return (1);
    }
    load_struct(headers, elf_file);


    print_task_0(headers, argv[0]);

    fclose(elf_file);
    return (0);
}