#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define BUF_SIZE 100

bool compareStr(char* str1, char* str2);
int getStrLen(char* str);


int main(int argc, char* argv[]) {
	int rfd;
	int count = 0;
	int wordLen, forLen;

	bool breakBool = false;

	char* word;
	char buf[BUF_SIZE] = { -1, };
	
	clock_t before_time;
	double timeSecond;


	if (argc < 3) {
		printf("./lab.out target_file word\n");
		return -1;
	}

	wordLen = getStrLen(argv[2]);
	rfd = open(argv[1], O_RDONLY);
	if (rfd == -1) {
		printf("Open %s\n", argv[1]);
		exit(1);
	}

	word = malloc(sizeof(char) * wordLen);

	before_time = clock();
	timeSecond = (double)(before_time / CLOCKS_PER_SEC); // 초 단위 변환

	while (read(rfd, buf, BUF_SIZE) > 0) {
		forLen = BUF_SIZE / wordLen;

		for (int i = 0; i < forLen; i++) {
			for (int k = 0; k < wordLen; k++) {
				word[k] = buf[i * (wordLen + 1) + k];

				if (buf[i * (wordLen + 1) + k] == '\0') {
					breakBool = true;
					break;
				}
			}
			
			if (breakBool)	break;

			printf("Compare the : %s", word);

			if (compareStr(argv[2], &(buf[i * (wordLen + 1)]))) {
				count++;
				printf(" - Matched!\n");
			}
			else printf("\n");
		}
	}
	printf("# of '%s' in the text file is %d\n", argv[2], count);
	printf("It takes %f seconds\n", ((double)clock() / CLOCKS_PER_SEC) - timeSecond);

	close(rfd);
	return 0;
}

int getStrLen(char* str) {
	int len = 0;

	while (str[len] != '\0') {
		len++;
	}
	return len;
}

bool compareStr(char* str1, char* str2) {
	int len = getStrLen(str1);

	for (int i = 0; i < len; i++) 
		if (str1[i] != str2[i]) 
			return false;
	return true;
}