#include "concept.h"
/**
* direntLoad - creates and loads myFile struct with the dirent struct info
* @target: the target directory for the ls command
* Return: pointer to the populated Myfile list
*/
struct myFile *direntLoad(char *target)
{
	DIR *dir;
	struct dirent *entity = NULL;
	struct myFile *fileList = NULL;
	size_t list_size = 0, i = 0, nameLength = 0;

	list_size = listLength(target);
	dir = opendir(target);
	entity = readdir(dir);
	fileList = malloc(list_size * sizeof(struct myFile));
	while (entity != NULL)
	{
		nameLength = stringLength(entity->d_name);
		fileList[i].dirent_info = entity;
		fileList[i].stat_info = NULL;
		fileList[i].userName = NULL;
		fileList[i].fileName = malloc((nameLength + 1) * sizeof(char));
		copyString(entity->d_name, fileList[i].fileName);
		entity = readdir(dir);
		i++;
	}
	closedir(dir);
	return (fileList);

}
/**
* statLoad - loads myFile struct with the stat struct info
* @fileList: list of structs being populated
* @target: target directory for the ls command
* Return: void
*/
void statLoad(struct myFile *fileList, char *target)
{
	char file_path[PATH_MAX + 1];
	size_t i = 0;
	size_t list_size = 0;

	list_size = listLength(target);
	while (i < list_size)
	{
		sprintf(file_path, "%s/%s", target, fileList[i].fileName);
		fileList[i].stat_info = malloc(sizeof(struct stat));
		lstat(file_path, fileList[i].stat_info);
		i++;
	}
}
/**
* listLength - gets the number of entries in the directory
* @target: the target directory for the ls command
* Return:  length of the list
*/
size_t listLength(char *target)
{
	DIR *dir;
	struct dirent *entity;
	size_t list_size = 0;

	dir = opendir(target);
	entity = readdir(dir);
	while (entity != NULL)
	{
		list_size++;
		entity = readdir(dir);
	}
	closedir(dir);
	return (list_size);
}
/**
* freeStructMembers - frees members of the myFile struct
* @fileList: the struct to free
* @target: the target directory for the ls command
* Return: 1 to swap, 0 if not -1 on error
*/
void freeStructMembers(struct myFile *fileList, char *target)
{
	size_t i = 0;

	while (i < listLength(target))
	{
		free(fileList[i].fileName);
		free(fileList[i].stat_info);
		i++;
	}
}
