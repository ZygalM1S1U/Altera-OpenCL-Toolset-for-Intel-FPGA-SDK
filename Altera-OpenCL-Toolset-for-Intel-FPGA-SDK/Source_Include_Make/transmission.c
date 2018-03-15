
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>


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
        sprintf(buffer69, "scp -6 -r %s root@\[%d::%d:%d:%d\]", dir_buffer, IP1, IP2, IP3, IP4);
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
