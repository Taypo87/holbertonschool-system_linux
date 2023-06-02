#include "concept.h"

/**
* sortStruct - Sorts structs by file name alphabetically
* @fileList: the array to be sorted
* Return: void
*/

void sortStruct(struct myFile *fileList, char *target)
{
	size_t i = 0;
	struct myFile temp;
	struct myFile temp2;
	int swap = 0;
	size_t list_size = 0;
	list_size = listLength(target);

	while (i < list_size - 1)
	{
		if (fileList[i].stat_info != NULL && fileList[i + 1].stat_info != NULL)
		{
		swap = compareString(fileList[i].fileName, fileList[i + 1].fileName);
			if (swap == 1)
			{   
				temp = fileList[i];
				temp2 = fileList[i + 1];
				fileList[i] = temp2;
				fileList[i+1] = temp;
				i = 0;
			}
			else 
			{
			i++;
			}
		}
		else
		{
			break;
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

void copyString(char *string, char *dest)
{
	size_t i = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		dest[i] = string[i];
	}
	dest[i] = '\0';
}