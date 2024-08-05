#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	struct passwd *pw;
	struct group *grp;
	FILE* wfp;
	int n;
	

	if ((wfp = fopen(argv[1], "w")) == NULL) {
		perror("fopen : result file");
		exit(1);
	}
	fprintf(wfp, "Same GID Different Name\n");

	while ((pw = getpwent()) != NULL) {
		grp = getgrgid(pw->pw_gid);
		if(strcmp(pw->pw_name, grp->gr_name))
			fprintf(wfp, "GID: %5d\t GName: %s\t Pname: %s\n", 
					pw->pw_gid, grp->gr_name, pw->pw_name);

	}
	fclose(wfp);

	return 0;
}
