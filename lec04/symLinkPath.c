#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PRINT_ERR_EXIT(_msg) {perror(_msg); exit(1);}

int main(void) {
	char buf[BUFSIZ];
	int n;
	
	n = readlink("linkC.txt", buf, BUFSIZ);
	if (n == -1) PRINT_ERR_EXIT("readlink");
	
	buf[n] = '\0';
	printf("linkC.txt : READLINK = %s\n", buf);

	realpath("linkC.txt", buf);
	printf("linkC.txt : REALPATH = %s\n", buf);
	return 0;
}
