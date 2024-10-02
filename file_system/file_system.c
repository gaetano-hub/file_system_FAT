#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "../include/file_system.h"


void *mmap_buff;

void *fs;

void init_file_system(const char* disk){
	int fd = open(disk, O_RDWR | O_CREAT, 0666);
	if(fd == -1){
		printf("errore");
		return;
	}

	ftruncate(fd, NUM_BLOCK);

	mmap_buff = mmap(NULL, DISK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);
	if(mmap_buff  == MAP_FAILED){
		printf("errore mmap");
		close(fd);
		return;
	}

	close(fd);

	






}