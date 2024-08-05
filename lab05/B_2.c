#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	struct passwd *pw;
	struct group *grp;

	while ((pw = getpwent()) != NULL) {
		grp = getgrgid(pw->pw_gid);
		printf("%s : %s\n", pw->pw_name, grp->gr_name);
	}

	return 0;
}

