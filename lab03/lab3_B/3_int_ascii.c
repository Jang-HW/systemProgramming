#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *rfp, *wfp;
	char buf[3];
	unsigned int decimal = 0, binary = 0b1;
	unsigned int n, itemSize = sizeof(char);

        if (argc < 3) {
                printf("./%s input output\n", argv[0]);
                return -1;
        }

	// file openning
	if ((rfp = fopen(argv[1], "r")) == NULL) {
		perror("fopen: input file");
		exit(1);
	}
	if ((wfp = fopen(argv[2], "w")) == NULL) {
		perror("fopen: output file");
		exit(1);
	}
	
	// read binary and write txt
	while ((n=fread(buf, itemSize, 3, rfp)) > 0) {
		for (int i = 2; i >= 0; i--){
			for (int k = 0; k < 8; k++){
				binary = 0;
				binary = (char)(buf[i] << (7 - k)) >> 7;
				if (binary == -1)
					decimal += (1 << (k + (2-i)*8));

				//printf("%d\n", binary);
			}
			//printf(" ");
		}
		fprintf(wfp, "%d ", decimal);
		printf("buf=%u\n", decimal);
		decimal = 0;
	}
	fclose(rfp);
	return 0;
}
