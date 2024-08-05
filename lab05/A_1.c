#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 		// chdir, sysconf
#include <sys/stat.h>		// mkdir
#include <sys/types.h>		// mkdir
#include <sys/utsname.h>	// uname
#include <sys/sysinfo.h>	// sysinfo

#define PRINT_ERR_EXIT(_msg) {perror(_msg); exit(1);}

int main(int argc, char *argv[]){
	struct utsname uts;
	struct sysinfo info;
	FILE *wfp;

	if (uname(&uts) == -1) {
		perror("uname");
		exit(1);
	}
	
	// 운영체제 이름으로 폴더 생성
	if (mkdir(uts.sysname, 0755) == -1)
		PRINT_ERR_EXIT(uts.sysname);
	// 장치 이름으로 폴더 생성
	if (mkdir(uts.nodename, 0755) == -1)
		PRINT_ERR_EXIT(uts.nodename);

	// 폴더 이동 후 파일 생성
	chdir(uts.sysname);
	
	if ((wfp = fopen("sysinfo.txt", "w")) == NULL) {
		perror("fopen : sysinfo.txt");
		exit(1);
	}
	
	sysinfo(&info);
	
	fprintf(wfp, "sysinfo()\n");
	fprintf(wfp, "Total usable memory : %lu KB\n", info.totalram);
        fprintf(wfp, "Available memory : %lu KB\n", info.freeram); 
        fprintf(wfp, "Now using memory : %lu KB\n", info.totalram - info.freeram); 
        fprintf(wfp, "Total swap space size : %lu KB\n", info.totalswap); 
        fprintf(wfp, "Swap space still available : %lu KB\n", info.freeswap); 
        fprintf(wfp, "Now using swap space : %lu KB\n", info.totalswap - info.freeswap); 
	fclose(wfp);

	chdir("..");

        // 폴더 이동 후 파일 생성
	chdir(uts.nodename);
        if ((wfp = fopen("sysconf.txt", "w")) == NULL) {
                perror("fopen : sysconf.txt");
                exit(1);
        }

        fprintf(wfp, "Max UID process : %ld\n", sysconf(_SC_CHILD_MAX));
        fprintf(wfp, "Max open file : %ld\n", sysconf(_SC_OPEN_MAX));
	fprintf(wfp, "Max UID * open file : %ld\n", sysconf(_SC_OPEN_MAX) * sysconf(_SC_CHILD_MAX));
	fclose(wfp);

        chdir("..");
}
