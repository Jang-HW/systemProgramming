#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int buf[5] = { 0 };
  FILE *fp = fopen("binary.bin", "wb");

  if(!fp){
	  fprintf(stderr, "Fail to open the file - %s\n", "binary.bin");
    exit(1);
  }

  size_t i= fread(buf, sizeof(int), 5, fp);
  printf("Success to write %ld object(s). \n", i); 
																			
	for (int i = 0; i < 5; i++)
		printf("%d ", buf[i]);

  fclose(fp);
  return 0;
}

