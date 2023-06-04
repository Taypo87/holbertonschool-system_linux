#ifndef _CONCEPT_
#define _CONCEPT_

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

/**
* myFile - struct containing information about files or directories
* @dirent_info: the dirent struct from readdir
* @stat_info: the stat struct fromn lstat
* @userName: username of the file
* @fileName: the file name
*/
struct myFile
{
	struct dirent *dirent_info;
	struct stat *stat_info;
	char *userName;
	char *fileName;
};

struct myFile *loadStruct(char *target);
void sortStruct(struct myFile *fileList, char *target);
int compareString(char *string1, char *string2);
size_t stringLength(const char *string);
struct myFile *direntLoad(char *target);
void statLoad(struct myFile *fileList, char *target);
size_t listLength(char *target);
void freeStructMembers(struct myFile *fileList, char *target);
void copyString(char *string, char *dest);
void printList(struct myFile *fileList, char *target);
int checkArg(char *target, char **argv);
void selectPrint(struct myFile *fileList, char *target, char option);
void printLista(struct myFile *fileList, char *target);
void printListA(struct myFile *fileList, char *target);
void printListl(struct myFile *fileList, char *target);
void convertOctal(mode_t perms, char *permissions);
const char *formatPerms(int permission);



#endif
