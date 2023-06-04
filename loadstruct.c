


struct myFile loadDirent(char *target)
{
    DIR *dir;
    struct dirent *entity;
    struct myFile *fileList;
    size_t list_size = 20, i = 0, nameLength = 0;

    fileList = malloc(list_size * sizeof(struct myFile));
    for (i = 0; i < list_size; i++)
    {
        
    }
}