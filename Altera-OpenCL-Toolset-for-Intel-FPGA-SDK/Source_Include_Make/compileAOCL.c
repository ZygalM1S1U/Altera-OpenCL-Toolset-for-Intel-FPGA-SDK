
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "boardConfig.h"

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
  /*printf("Username on device to connect to?\n");
  scanf("%s", &userz);
  printf("What is the IP for the device you would like to send the key to?\n");
  //scanf("%d.%d.%d.%d", &IP11, &IP12, &IP13, &IP14);
  //sprintf(buffer69, "ssh-copy-id %s@%d.%d.%d.%d", userz, IP11, IP12, IP13, IP14);
  system((char*)buffer69);*/
}
