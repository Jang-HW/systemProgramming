#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int printFiles(char dirName[], char *folder[], const char *target);

static char rootFolder[BUFSIZ];

int main(int argc, char *argv[])
{
	DIR *dp;
	char *folder[BUFSIZ] = { '\0', };

	getcwd(rootFolder, BUFSIZ);

	if ((dp = opendir(argv[1])) == NULL) {
		perror("opendir - input Folder error : ");
		exit(1);
	}
	
	// 출력 함수 호출 
	printFiles(argv[1], folder, argv[2]);
	
	for(int i= 0; i < BUFSIZ; i++){
		if (folder[i] != NULL && strlen(folder[i]) != 0) {
			printFiles(folder[i], folder, argv[2]);
	        }
	}

	for(int i= 0; i < BUFSIZ; i++){
		if (folder[i] != NULL && strlen(folder[i]) != 0) 
 			free(folder[i]);  // Free the allocated memory
	}

	closedir(dp);
	return 0;
}


int printFiles(char dirName[], char *folder[], const char *target){
	DIR *dp;
	struct dirent *dent;
	int cmp_result = 0, arr_len = 0;

        if ((dp = opendir(dirName)) == NULL) {
                perror("opendir - input Folder error : ");
                exit(1);
        }

	chdir(dirName);

        while ((dent = readdir(dp))) {
		cmp_result = strcmp(dent->d_name, target);

                if((!cmp_result) && (dent->d_type != DT_DIR))
                	printf("%s/%s \n", dirName, dent->d_name);

		else if (dent->d_type == DT_DIR && dent->d_name[0] != '.'){
			for (int i = 0; i < BUFSIZ; i++){
				if (folder[i] != NULL && strlen(folder[i]) != 0)	arr_len++;
				else 	break;
			}
			char *newFolder = (char *)malloc(BUFSIZ);

			snprintf(newFolder, BUFSIZ, "%s/%s", dirName, dent->d_name);
			folder[arr_len] = newFolder;
		}

        }
	chdir(rootFolder);
}
