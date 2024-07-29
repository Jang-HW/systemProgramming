#include <stdio.h>

#define PROCESS_CNT 4

int main(int argc, char *argv[])
{
	int 	arrive_tim[PROCESS_CNT];
	int 	burst_tim[PROCESS_CNT];
	int 	now_process = 0;
	int 	now_time = 0;
       	int 	burst_cnt = 0;
	FILE 	*rfp = fopen("input.txt", "r");

	fscanf(rfp, "%d %d %d %d\n", &arrive_tim[0],&arrive_tim[1],&arrive_tim[2],&arrive_tim[3]);
	fscanf(rfp, "%d %d %d %d\n", &burst_tim[0],&burst_tim[1],&burst_tim[2],&burst_tim[3]);

	for(int i =0; i< 4;i++){
		printf("Process %c - arrive Time : %2d, burst Time : %2d\n", \
				'A'+i, arrive_tim[i], burst_tim[i]);
	}

	//
	printf("Chart : ");

	while (1)
	{
		if(now_time < arrive_tim[now_process])
			printf("X");
		else {
			printf("%c", 'A'+now_process);
			burst_cnt++;
			if(burst_cnt >= burst_tim[now_process]){
				now_process++;
				burst_cnt = 0;
			}
			if(now_process >= PROCESS_CNT)
				break;
		}
		now_time++;
	}
	//*/
	
	printf("\n\n");
	fclose(rfp);

	return 0;
}
