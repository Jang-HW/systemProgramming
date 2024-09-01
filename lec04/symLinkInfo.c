#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define PRINT_CNT_INODE {\
printf("unix.txt : Link Count = %d\n", (int)buf.st_nlink);\
printf("unix.txt : Inode = %d\n", (int)buf.st_ino); }

int main(void) {
	struct stat buf;
	
	printf("1. stat : linkA.txt ---\n");
	stat("linkA.txt", &buf);
	PRINT_CNT_INODE;
	
	printf("2. stat : linkB.txt ---\n");
	stat("linkB.txt", &buf);
	PRINT_CNT_INODE;
	
	printf("3. lstat : linkC.txt ---\n");
	lstat("linkC.txt", &buf);
	PRINT_CNT_INODE; 
	
	return 0;
}
