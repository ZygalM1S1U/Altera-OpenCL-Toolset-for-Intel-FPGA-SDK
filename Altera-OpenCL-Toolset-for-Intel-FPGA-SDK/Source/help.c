#include <aocltoolset.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>



int Memcheck() {
	int *sack, *sack1, ay1 = 0;
	printf("Loading...\n");
	sack = malloc(1 * sizeof(*sack));
	sack1 = malloc(1 * sizeof(*sack1));
	if (sack == NULL) {
		printf("Error, out of memory. Error Code: 1\n");
		getchar();
		ay1 = 2;
		free(sack);
		return 1;
	}
	else {
		printf("\n");
		int *temp = realloc(sack, 1 * sizeof(int));
		if (temp != NULL) {
			sack = temp;
		}
		else {
			free(sack);
			ay1 = 4;
			printf("Error, plumbing unsuccessful. Error Code 3.\n");
			getchar();
		}

	}
	if (sack1 == NULL) {
		printf("Error, out of memory.  Error Code 2\n");
		getchar();
		ay1 = 3;
		free(sack1);
		return 1;
	}
	else {
		printf("Load successful.\n");
		printf("Press any button to continue...\n");
		getchar();
		ay1 = 1;
		int *temp1 = realloc(sack1, 1 * sizeof(int));
		if (temp1 != NULL) {
			sack1 = temp1;
		}
		else {
			free(sack1);
			printf("Error, plumbing not successful.  Error Code 4.\n");
			getchar();
			ay1 = 5;
		}
	}
}

void helpScreen() {

  int exit = 0;
  char configure[15];

  printf("Welcome to the help screen.\n");
  printf("Which function would you like to know more about?\n");
  while(exit != 1) {
    printf("\nOptions:\nSend\nCompile\nExit\n");
    printf("User Cursor: ");
    scanf("%s",&configure);
    switch (strlen(configure)) {
      case 4:
        for(int i=0; i <= 1; ++i)
        {
          if(configure[i] == 'S')
          {
            printf("The Send function is able to send a file stream to a given board via scp.\nBoth inet6 addresses and ipv4 addresses are allowed.\n");
            printf("Put some examples in here\n");
          }
          else if(configure[i] == 'E')
          {
            exit = 1;
            printf("Exiting the help screen...\n");
          }
          else
          {
          printf("\nIncorrect command, try again.\n");
          }
        }
        break;
        case 7:
        printf("The Compile library has a few options ARM and Board Manager\nARM deals with ARM compilation on the Host PC.\n");
    }
  }
}
