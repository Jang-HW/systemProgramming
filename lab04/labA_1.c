#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	int c;
	char *find_c;

	DIR *dp;
	struct dirent *dent;
	FILE *rfp, *wfp;
	
	// 우선 폴더가 있는지 확인
	if ((dp = opendir("A_1")) == NULL) {
		perror("opendir: A_1");
		exit(1);
	}

	// 작성할 파일 열기
	if ((wfp = fopen("sum.txt", "w")) == NULL) {
		perror("fopen: sum.txt");
		exit(1);
	}
	
	// 상대 경로 변경을 위한 작업 폴더 변경 
	chdir("A_1");

	// 폴더 내의 파일 순회
	while ((dent = readdir(dp))) {
		// 파일 이름이 .c로 끝나는지 확인
		if(!(find_c = strstr(dent->d_name, ".c\0")))
			continue;
		if (strlen(find_c) != 2)
			continue;

		//.c로 끝나면 이름 출력 후, 파일을 열어서 복붙
		printf("%s\n", dent->d_name);

		if ((rfp = fopen(dent->d_name, "r")) == NULL) {
			perror("fopen");
			exit(1);
		}
		while ((c = fgetc(rfp)) != EOF) 
			fputc(c, wfp);

	}
	
	fclose(rfp);
	fclose(wfp);
	closedir(dp);
	return 0;
}
