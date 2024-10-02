#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



#define DISK_SIZE (1024 * 1024);
#define BLOCK_SIZE 256;
#define MAX_NUM_BLOCK (DISK_SIZE / CLUSTER_SIZE);

typedef struct
{
	char file_system_name[8];
	int first_block;
	int size;
	int is_drcty; //0=file 1=directory
	/*Directory *dir; //puntatore directory*/
}FileHandle;


/*
typedef struct
{
	FileHandle entries[MAX_NUM_BLOCK]; //array di file e sottodirectory
	int file_count//num di file nella directory
}Directory;
*/