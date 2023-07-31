#include "objdump.h"

void nm_wrapper(int fd)
{
    // here we just want to check if its 32 or 64 bit, map the appropriate bitheader
    Elf64_Ehdr *pElfHeader;
    Elf64_Shdr *ppSectionHeader, *pSymbolTableSection, *pStrtabSection;
    Elf64_Sym *pSymbolTable;
    void *mapped_file;
    int i, SymbolCount;
    char *strtab;
    struct stat st;

    printf("break 0");
    fstat(fd, &st);
    printf("break 1");
    mapped_file = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    printf("break 2");
    pElfHeader = (Elf64_Ehdr *)mapped_file;
    printf("break 3");
    ppSectionHeader = (Elf64_Shdr *)mapped_file + pElfHeader->e_shoff;
    printf("break 4");
    for (i = 0; i < pElfHeader->e_shnum; i++)
    {
        if (ppSectionHeader[i].sh_type == SHT_SYMTAB)
        {
            pSymbolTableSection = &ppSectionHeader[i];
            break;
        }
    }
    printf("break 5");
    pStrtabSection = ppSectionHeader + pSymbolTableSection->sh_link;
    printf("break 6");
    strtab = mapped_file + pStrtabSection->sh_offset;
    printf("break 7");
    pSymbolTable = (Elf64_Sym *)((char *)mapped_file + pSymbolTableSection->sh_offset);
    printf("break 8");
    SymbolCount = pSymbolTableSection->sh_size / sizeof(Elf64_Sym);
    printf("break 9");
    for (i = 0; i < SymbolCount; i++)
    {
        printf("Symbol name is %s\n", strtab + pSymbolTable[i].st_name);
    }
    munmap(mapped_file, pElfHeader->e_shoff + pElfHeader->e_shnum * sizeof(Elf64_Shdr));
}
