#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
	int i, j, num, size_arr = 1, curve = 0;
	char count = 1, h_cnt = 0, w_cnt = 0;
	char snail[50][50] = {0, };

	do{
		if (num > 50 || num < 1)
			printf("num < 1 || num > 50\n숫자를 잘못 입력했습니다.\n");

		printf("num == ");
	        scanf("%d", &num);
	}while (num < 1 || num > 50);

	size_arr = num;

	while(num > 0){
		switch (curve % 4){
			case 0:
				h_cnt = curve / 4;
				w_cnt = curve / 4;
				for (i = 0; i < num; i++){
					snail[h_cnt][w_cnt + i] = count;
					count++;
					count %= 10;
				}
				break;
			case 1:
				h_cnt = curve / 4 + 1;
				w_cnt = (size_arr-1) - (curve / 4);
				for (i = 0; i < num; i++){
					snail[h_cnt + i][w_cnt] = count;
					count++;
					count %= 10;
				}
			      	break;
			case 2: 
				h_cnt = (size_arr-1) - (curve / 4);
				w_cnt = (size_arr-1) - (curve / 4) - 1;
				for (i = 0; i < num; i++){
					snail[h_cnt][w_cnt-i] = count;
					count++;
					count %= 10;
				}
				break;
			case 3:
				h_cnt = (size_arr-1) - (curve / 4) - 1;
				w_cnt = curve / 4;
				for (i = 0; i < num; i++) {
					snail[h_cnt-i][w_cnt] = count;
					count++;
					count %= 10;
				}
		}
		curve++;

		if(curve%2)
			num--;

	}

	for (i = 0; i < size_arr; i++){
		for (j = 0; j < size_arr; j++)
			printf("%d ", snail[i][j]);
		printf("\n");
	}

	return 0;
}
