#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User 
{
	int mID;
	int mScore[10];
};

int main(int argc, char* argv[])
{
	FILE *rfp_b, *rfp_t;
	struct User buf;
	int n;
	int itemSize = sizeof(struct User);
	clock_t before_time;
	double timeSecond;

	if (argc < 3) {
                printf("./%s.out binFile textFile\n", argv[0]);
                return -1;
        }
	
	rfp_b = fopen(argv[1], "r");
	if (rfp_b == NULL) {
		printf("Open bin file error %s\n", argv[1]);
		exit(1);
	}
	printf("argv[1], path of binary file : %s\n", argv[1]);

	rfp_t = fopen(argv[2], "r");
	if (rfp_t == NULL) {
		printf("Open text file error %s\n", argv[2]);
		exit(1);
	}
	printf("argv[2], path of text file : %s\n", argv[2]);

	
	before_time = clock();
	timeSecond = (double)(before_time / CLOCKS_PER_SEC); // 초 단위 변환

	while ((n=fread(&buf, itemSize, 1, rfp_b)) > 0) {
		continue;
	}	
	printf("[ result of reading binary file ]\n");
	printf("It takes %f milli-seconds\n", ((double)clock() / CLOCKS_PER_SEC) - timeSecond*1000);
	
	// ----- bin ------ //

	before_time = clock();
        timeSecond = (double)(before_time / CLOCKS_PER_SEC); // 초 단위 변환

        while ((n=fscanf(rfp_t, "%d %d %d %d %d %d %d %d %d %d %d", &buf.mID, &buf.mScore[0],\
					&buf.mScore[1], &buf.mScore[2], &buf.mScore[3], \
					&buf.mScore[4], &buf.mScore[5], &buf.mScore[6], \
					&buf.mScore[7], &buf.mScore[8], &buf.mScore[9])) != EOF) {
                continue;
        }
        printf("[ result of reading text file ]\n");
        printf("It takes %f milli-seconds\n", ((double)clock() / CLOCKS_PER_SEC) - timeSecond*1000);


	fclose(rfp_b);
	fclose(rfp_t);

	return 0;
}
