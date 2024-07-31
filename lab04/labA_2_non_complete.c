#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	long offsetFind = 0;
	char wd[BUFSIZ];
	long offset = 0;

	DIR *dp, *dp_search;
	struct dirent *dent;
	char *targetDir;

	
	offsetFind = (long)'U' + (long)'b' + (long)'u' + (long)'n' + (long)'t' + (long)'u';
	offsetFind %= 12;

	if ((dp = opendir("A_2")) == NULL) {
		perror("opendir");
		exit(1);
	}

	chdir("A_2");

        while (dent = readdir(dp)){
		if(opendir(dent->d_name) == NULL)
			continue;
		printf("Read : %5s Cur Offset : %ld\n", dent->d_name, telldir(dp));

		if(telldir(dp) == offsetFind)
			strcpy(wd, dent->d_name);
        }

	if(chdir(wd) < 0) perror("chdir");
	
	seekdir(dp, offsetFind);
	getcwd(wd, BUFSIZ);
	printf("\n");

	while (dent = readdir(dp)) {
		if(dent->d_reclen == 0){
			rmdir (dent->d_name);
			printf("%s 폴더를 삭제했습니다. \n", dent->d_name);
		}
		else {
			getcwd(wd, BUFSIZ);
		        printf("%s\n", wd);
		}
	}
	
	closedir(dp);
	return 0;
}
