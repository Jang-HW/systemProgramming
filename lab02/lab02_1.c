#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>

int main(int argc, char *argv[]) {
	int rfd, wfd, n;
	int cpNum = 0;
	char buf[10];

	clock_t before_time;
	double timeSecond;


	if (argc < 4) {
		printf("./lab.out 대상파일 복사경로 크기\n");
		return -1;
	}

	printf("Copy %s to %s (chunk size = %s)\n", argv[1], argv[2], argv[3]);

	rfd = open(argv[1], O_RDONLY);
	if (rfd == -1) {
		printf("Open %s\n", argv[1]);
		exit(1);
	}

	wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (wfd == -1) {
		printf("Open %s\n", argv[2]);
		exit(1);
	}
	
	before_time = clock();
	timeSecond = (double)(before_time / CLOCKS_PER_SEC); // 초 단위 변환

	while (cpNum < atoi(argv[3]) && ((n = read(rfd, buf, 1)) > 0)) {
		if (write(wfd, buf, n) != n) printf("Write\n");
		cpNum++;
	}
	printf("It takes %f seconds\n", ((double)clock() / CLOCKS_PER_SEC) - timeSecond);
	if (n == -1) printf("Read");

	close(rfd);
	close(wfd);

	return 0;
}
