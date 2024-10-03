#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



#define DISK_SIZE (1024 * 1024)
#define BLOCK_SIZE 512
#define MAX_NUM_BLOCK 2048
#define FREE_FAT 0
#define EOF (-1)



typedef struct
{
	char name[8];
	int first_block;
	int size;
	int is_drcty; 		//0=file 1=directory
	struct Directory *dir; 		//puntatore directory
}FileHandle;

typedef struct Directory
{
	FileHandle entries[MAX_NUM_BLOCK]; 		//array di file e sottodirectory
	int file_count;		//num di file nella directory
}Directory;

//funzione di init del FS
void initFS(const char* name);

//formattazione disk
void erase_disk();





