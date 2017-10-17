/*
Author: James A. Novorita
Affliation: Western Michigan University
Department: Electrical and Computer Engineering
Section: Parallel Computing and Data Science
Summary:
This toolset is incomplete and requires more work.  Commits will be made as time goes on.  The purpose of this toolset is to
allow for a smoother development cycle of OpenCL on the fly, in C.  This gives a basic interface for the developer and making
the obscure compilation and transfer process a bit easier with AOCL.

12-Oct-17
Changes Committed:
inet6 and IPV4 send commands for compilation were modified.  No directory was previosuly set for the target.
14-Oct-17
Changes commited:
Dynamic memory allocation was added to certain pieces of the program.
16-Oct-17
changes commited:
An interface for board configuration files was made along with adjustable settings which save as a text file.  DMA was used for
file manipulations and management.  Functions to test DMA were also implemented as well as part of an interface for compilation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#define CHUNK 1024 /* read 1024 bytes at a time */



int main() {

  char configure[10];
  int memReady = 0;

  memReady = Memcheck(memReady);
  if(memReady == 1)
  {
    printf("Error\n");
  }
  printf("Welcome to WMU's toolbelt for OpenCL FPGA SDK, what would you like to do?\n");
  while (1)
  {
    printf("\nOptions:\nSend\nCompile\nHelp\nExit\n");
    printf("User Cursor: ");
    scanf("%s",&configure);
    switch (strlen(configure)) {
      case 4:
        for(int i=0; i <= 1; ++i)
        {
          if(configure[i] == 'H')
          {
            printf("Here is the help screen\n");
          }
          else if(configure[i] == 'S')
          {
            Send();
          }
          else if(configure[i] == 'E')
          {
            return 0;
          }
          else
          {
          //  printf("\nIncorrect command, try again.\n");
          }
        }
        break;
        case 7:
          Compile();
    }
  }
}
  void Compile()
  {
    unsigned short int IP1, IP2, IP3, IP4;
    unsigned short int IP5, IP6, IP7, IP8;
    char sys_buffer[40];
    char buffer69[20];
    char userz[25];

    printf("Compile Menu:\nOpenCL\nARM\nBoard Manager\n");
    scanf("%s", &userz);
    if(strlen(userz) == 4)
    {
      printf("ARM GCC menu\n");
    }
    else if(strlen(userz) == 7)
    {
      printf("OpenCL menu:\nCompile Kernel File\n ");
    }
    else
    {
      BoardConfig();
    }
    printf("Username on device to connect to?\n");
    scanf("%s", &userz);
    printf("What is the IP for the device you would like to send the key to?\n");
    //scanf("%d.%d.%d.%d", &IP11, &IP12, &IP13, &IP14);
    //sprintf(buffer69, "ssh-copy-id %s@%d.%d.%d.%d", userz, IP11, IP12, IP13, IP14);
    system((char*)buffer69);
}

  void Send()
  {
    unsigned short int IP1, IP2, IP3, IP4;
    unsigned short int IP5, IP6, IP7, IP8;
    char sys_buffer[40];
    char dir_buffer[40];
    char buffer69[20];
    char protocol[25];

    printf("This will use secure copy on Intel's Embedded ARM Shell for Windows\n");
    printf("Please specify the name of the directory of compiled files you would like to send to the FPGA\n");
    scanf("%s", &dir_buffer);
    printf("To send data to the FPGA, an IP needs to be specified. On the PuTTy terminal, type: 'ifconfig' to find the proper one.\n");
    printf("Send Options for program:\nipv4\ninet6\nuser cursor: ");
    scanf("%s", &protocol);
    for(int i = 0; i <= 2; ++i) {
      if(i == 1){
        if(protocol[i] == 'n')
        {
          printf("What is the inet6 address for the device you would like to send the directory to?\n");
          scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
          sprintf(buffer69, "scp -6 -r %s root@\[%d:%d:%d:%d\]", dir_buffer, IP1, IP2, IP3, IP4);
          system((char*)buffer69);
        }
        else
        {
            printf("What is the IPV4 for the device you would like to send the key to?\n");
            scanf("%d.%d.%d.%d", &IP5, &IP6, &IP7, &IP8);
            sprintf(buffer69, "scp -r %s root@%d.%d.%d.%d",dir_buffer, IP5, IP6, IP7, IP8);
            system((char*)buffer69);
        }
      }
    }
}

  void BoardConfig() {
    FILE *fp, *fp1;
    char G1[255] = "boardnames.txt";
    char *Board_List;
    int fileSize;
    long lSize;
    char buf[CHUNK];
    FILE *file;
    size_t nread;

    fileSize =
    fp = fopen(G1, "rb");
  	if (!fp) perror(G1), exit(1);
    fseek(fp, 0L, SEEK_END);
    lSize = ftell(fp);
    rewind(fp);

    /* allocate memory for entire content */
    Board_List = calloc(1, lSize + 1);
    if (!Board_List) fclose(fp), fputs("memory alloc fails\n", stderr), getchar(), exit(1);

    /* copy the file into the buffer */
    if (1 == fread(Board_List, lSize, 1, fp))
      fclose(fp), free(Board_List), fputs("entire read fails\n", stderr), getchar(), exit(1);

    if(lSize == 0)
    {
      printf("There are currently no boards saved.  Would you like to set up a configuration setting for your board to make compilation faster?\n");
    }
    else
    {
      printf("Boards configred:\n");
      printf("\n");
      if (fp)
      {
          while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
              fwrite(buf, 2, nread, stdout);
          if (ferror(file))
          {
              printf("Corrupted board list.\n");
          }
          fclose(file);
      }
    }
  /*  printf("Make sure the working directory is set properly.\nWhat is the filename for the first genome?\n");
    scanf("%s", G1);
    strcat(G1, ".txt");
  */
}

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
