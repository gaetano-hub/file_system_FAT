#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>

#include "../include/file_system.h"


void *mmap_buff;

Directory *root_dir;
Directory *current_drcty;

void syncFS(){
	msync(mmap_buff, DISK_SIZE, MS_SYNC);
}

void print_directory_contents(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        printf("%s\n", dir->entries[i].name);
    }
}

// Per stampare il contenuto della directory radice



void initFS(const char* disk){
	int fd = open(disk, O_RDWR | O_CREAT, 0666);
	if(fd == -1){
		printf("errore");
		return;
	}

	ftruncate(fd, MAX_NUM_BLOCK);

	mmap_buff = mmap(NULL, DISK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);
	if(mmap_buff  == MAP_FAILED){
		printf("errore mmap");
		close(fd);
		return;
	}

	close(fd);

	root_dir = (Directory*) mmap_buff;
	printf("root_dir->file_count: %d\n", root_dir->file_count);

	if(root_dir->file_count == 0){
		root_dir->file_count = 0;

		FileHandle root;
		strcpy(root.name, "root/");
		root.first_block = 0;
		root.size = 0;
		root.is_drcty = 1;
		root.dir = root_dir; // punta a se stessa

		root_dir->entries[0] = root;
		root_dir->file_count = 1;

		print_directory_contents(root.dir);

		//sincronizza il file system
		syncFS();

	}


	current_drcty = root_dir;

	printf("init eseguita");

}

void erase_disk(){

	memset(mmap_buff, 0, DISK_SIZE);

	root_dir = (Directory*) mmap_buff;
	printf("root_dir->file_count: %d\n", root_dir->file_count);

	if(root_dir->file_count == 0){
		root_dir->file_count = 0;

		FileHandle root;
		strcpy(root.name, "root/");
		root.first_block = 0;
		root.size = 0;
		root.is_drcty = 1;
		root.dir = root_dir; // punta a se stessa

		root_dir->entries[0] = root;
		root_dir->file_count = 1;

		print_directory_contents(root.dir);

		//sincronizza il file system
		syncFS();

	}


	current_drcty = root_dir;

	printf("formattazione eseguita");
	
}


// =========GESTIONE FILE===========

int createFile(const char* fileName){

	FileHandle newFile;



	for (int i = 0; i < current_drcty->file_count; i++) {
        printf("%s\n", current_drcty->entries[i].name);
    }

	return 0;
}



