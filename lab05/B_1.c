#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shadow.h>

int main(int argc, char *argv[])
{
	struct spwd *spwd;
	char *pw_ptr;

	if ((spwd = getspnam(argv[1])) != NULL){
		pw_ptr = strtok(spwd->sp_pwdp, "$");
                printf("Hashid = %s\n", pw_ptr);

		pw_ptr = strtok(NULL, "$");
                printf("Salt = %s\n", pw_ptr);

		pw_ptr = strtok(NULL, "$");
                printf("Hash value = %s\n", pw_ptr);

		printf("last change date : %ld/%ld/%ld\n", 
				1970 + (spwd->sp_lstchg / 365), 
				1 + ((spwd->sp_lstchg / 30) % 12), 
				1 + (spwd->sp_lstchg % 30));
	}
	else {
		perror("input ID is not matched.\n");
	}

	return 0;
}
