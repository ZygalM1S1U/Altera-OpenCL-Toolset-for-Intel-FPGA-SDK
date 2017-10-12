/*
This program is to assist as a toolset for OpenCl's FPGA SDK.  Since the OpenCL has a certain standard and procedure of compiling and transferring mehods to
the board, this tool set was written to assist in plain english.
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



int main() {

  char configure[10];

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
          printf("Here is where the compile function will be called.\n");
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

  /*  printf("\n");
    sprintf(sys_buffer, "ssh-keygen -t dsa");
    system((char*)sys_buffer);
    printf("Username on device to connect to?\n");
    scanf("%s", &userz);
    printf("What is the IP for the device you would like to send the key to?\n");
    //scanf("%d.%d.%d.%d", &IP11, &IP12, &IP13, &IP14);
    //sprintf(buffer69, "ssh-copy-id %s@%d.%d.%d.%d", userz, IP11, IP12, IP13, IP14);
    system((char*)buffer69);
    */
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
          printf("What is the inet6 address for the device you would like to send the key to?\n");
          scanf("%d.%d.%d.%d", &IP1, &IP2, &IP3, &IP4);
          sprintf(buffer69, "scp -6 -r %dir_buffer root@\[%d:%d:%d:%d\]", dir_buffer, IP1, IP2, IP3, IP4);
          system((char*)buffer69);
        }
      }
      else
      {
        continue;
      }
    }
  /*  printf("What is the IP for the device you would like to send the key to?\n");
    scanf("%d.%d.%d.%d", &IP5, &IP6, &IP7, &IP8);
    sprintf(buffer69, "ssh-copy-id root@%d.%d.%d.%d", IP5, IP6, IP7, IP8);
    system((char*)buffer69);
*/
  }
