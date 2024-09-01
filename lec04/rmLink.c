#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define PRINT_ERR_EXIT(_msg) {perror(_msg); exit(1);}
int main(void) {
	int cnt;	
	cnt = unlink("unix.txt");
	
	if (cnt == -1)
		PRINT_ERR_EXIT("Unlink unix.txt")
	
	printf("Unlink unix.txt success!!!\n");
	return 0;
}

