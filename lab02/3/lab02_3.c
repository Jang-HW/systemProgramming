#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
	char buf[1];
	int rfd, wfd, n;
	int count = 0;
	clock_t before_time;
	double timeSecond;


	if (argc < 3) {
		printf("./lab.out targetFile writeFile\n");
		return -1;
	}

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

	while ((n = read(rfd, buf, 1)) > 0) {
		//printf("\n%s, %d\n", buf, count);

		if (count > 0) count--;

		else if (*buf >= 32 && *buf <= 127)
			if (write(wfd, buf, n) != n)
				printf("write error\n");
			else 
				printf("%s", buf);

		else count = *buf % 32;
	}

	printf("\n");
	printf("It takes %f seconds\n", ((double)clock() / CLOCKS_PER_SEC) - timeSecond);
	if (n == -1) printf("Read");

	close(rfd);
	close(wfd);

	return 0;
}

