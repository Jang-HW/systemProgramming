#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int printFiles(DIR *dp, const char *path, const char *target);

int main(int argc, char *argv[])
{
	DIR *dp;

	chdir(argv[1]);

	if ((dp = opendir(".")) == NULL) {
		perror("opendir - input Folder error : ");
		exit(1);
	}
	
	// 출력 함수 호출 
	printFiles(dp, argv[1], argv[2]);
	
	closedir(dp);
	return 0;
}


int printFiles(DIR *dp, const char *path, const char *target) {
	struct stat buf;
	struct dirent *dent;
	int fileType = 0;

	if	(strcmp(target, "F"))	fileType = S_IFIFO;
	else if	(strcmp(target, "D"))	fileType = S_IFDIR;
        else if	(strcmp(target, "R"))	fileType = S_IFREG;
	else if	(strcmp(target, "B"))	fileType = S_IFBLK;
        else if	(strcmp(target, "I"))	fileType = S_IFLNK;
	
	printf("%d\n", fileType);

        while ((dent = readdir(dp))) {
                stat(dent->d_name, &buf);
		if ((buf.st_mode & S_IFMT) == fileType)
                	printf("%s/%s \n", path, dent->d_name);

        }
}
