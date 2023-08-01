#include "objdump.h"

void nm_wrapper(int fd)
{
    // here we just want to check if its 32 or 64 bit, map the appropriate bitheader
    Elf64_Ehdr *pElfHeader;
    Elf64_Shdr *ppSectionHeader, *pSymbolTableSection, *pStrtabSection;
    Elf64_Sym *pSymbolTable;
    Elf64_Addr symbolAddress;
    void *mapped_file;
    int i, SymbolCount, symbolType;
    char *strtab;
    struct stat st;
    size_t x;

    fstat(fd, &st);
    mapped_file = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    pElfHeader = (Elf64_Ehdr *)mapped_file;
    ppSectionHeader = (Elf64_Shdr *)((char *)mapped_file + pElfHeader->e_shoff);
    for (i = 0; i < pElfHeader->e_shnum; i++)
    {
        if (ppSectionHeader[i].sh_type == SHT_SYMTAB)
        {
            pSymbolTableSection = &ppSectionHeader[i];
            break;
        }
    }
    pStrtabSection = ppSectionHeader + pSymbolTableSection->sh_link;
    strtab = mapped_file + pStrtabSection->sh_offset;
    pSymbolTable = (Elf64_Sym *)((char *)mapped_file + pSymbolTableSection->sh_offset);
    SymbolCount = pSymbolTableSection->sh_size / sizeof(Elf64_Sym);
    for (i = 0; i < SymbolCount; i++)
    {
        symbolAddress = pSymbolTable[i].st_value;
        symbolType = ELF64_ST_TYPE(pSymbolTable[i].st_info);
        printf("0x%016lx ", symbolAddress);
        handleSymbolType(symbolType);
        printf("%s\n", strtab + pSymbolTable[i].st_name);
    }
    munmap(mapped_file, pElfHeader->e_shoff + pElfHeader->e_shnum * sizeof(Elf64_Shdr));
}

void handleSymbolType(int symbolType)
{
    switch (symbolType)
    {
        case STT_NOTYPE:
            printf("U ");
            break;
        case STT_OBJECT:
            printf("O ");
            break;
        case STT_FUNC:
            printf("T ");
            break;
        case STT_SECTION:
            printf("S ");
            break;
        case STT_FILE:
            printf("F ");
            break;
        case STT_COMMON:
            printf("C ");
            break;
        case STT_TLS:
            printf("T ");
            break;
        case STT_REL:
            printf("S ");
            break;
        case STT_GNU_IFUNC:
            printf("i ");
            break;
        case STT_HIOS:
            printf("o ");
            break;
        case STT_LOPROC:
            printf("p ");
            break;
        case STT_HIPROC:
            printf("p ");
            break;
        default:
            printf("Symbol type: Unknown\n");
            break;
    }
}