#include "concept.h"
/**
* loadStruct - opens a directory and fills myFile struct array
* @target: the target directory
* Return: pointer to the populated struct array
*/
struct myFile *loadStruct(char *target)
{
	DIR *dir;
	struct stat fileStat;
	struct dirent *entity;
	struct myFile *fileList;
	size_t list_size = 20, i = 0, nameLength = 0;
    char file_path[PATH_MAX + 1];

	fileList = malloc(list_size * sizeof(struct myFile));
	dir = opendir(target);	  
	entity = readdir(dir);
	while (entity != NULL)
	{
        nameLength = stringLength(entity->d_name);
        sprintf(file_path, "%s/%s", target, entity->d_name);
		fileList[i].dirent_info = entity;
		fileList[i].userName = NULL;
        fileList[i].fileName = malloc((nameLength + 1) * sizeof(char));
        fileList[i].fileName[0] = '\0';
		sprintf(fileList[i].fileName, "%s", entity->d_name);
		lstat(file_path, &fileStat);
		fileList[i].stat_info = fileStat;
		entity = readdir(dir);
		i++;
		if (i == (list_size - 1))
		{
			list_size += 20;
			fileList = realloc(fileList, list_size * sizeof(struct myFile));
		}
	}
	closedir(dir);
	return (fileList);
}

/**
* sortStruct - Sorts structs by file name alphabetically
* @fileList: the array to be sorted
* Return: void
*/

void sortStruct(struct myFile *fileList)
{
	int i = 0;
	struct myFile temp;
	struct myFile temp2;
	int swap = 0;

	while (fileList[i + 1].fileName != NULL && fileList[i].fileName[0] != '\0')
	{
		swap = compareString(fileList[i].fileName, fileList[i + 1].fileName);
		if (swap == 1)
		{   
			temp = fileList[i];
			temp2 = fileList[i + 1];
			fileList[i] = temp2;
			fileList[i+1] = temp;
			i++;
		}
		else 
		{
			i++;
		}
	}
}
/**
* compareString - compares two strings for sorting alphabetically
* @string1: string to compare
* @string2: string to compare to
* Return: 1 to swap, 0 if not -1 on error
*/
int compareString(char *string1, char *string2)
{
	int i = 0;
	char stringValue1;
	char stringValue2;

	while(string1[i] != '\0')
	{
		stringValue1 = string1[i];
		stringValue2 = string2[i];

        if (stringValue1 == '\0' && stringValue2 == '\0')
        {
            return (-1);
        }
        if (stringValue1 == '\0' && stringValue2 != '\0')
        {
            return (0);
        }
        if (stringValue1 != '\0' && stringValue2 == '\0')
        {
            return (1);
        }
		if(stringValue1 > 64 && stringValue1 < 91)
		{
			stringValue1 += 32;
		}
		if(stringValue2 > 64 && stringValue2 < 91)
		{
			stringValue2 += 32;
		}
		if (stringValue1 > stringValue2)
		{
			return (1);
		}
		if (stringValue1 < stringValue2)
		{
			return (0);
		}
		i++;
	}
    return (-1);
}

size_t stringLength(const char *string)
{
    size_t length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return(length);
}