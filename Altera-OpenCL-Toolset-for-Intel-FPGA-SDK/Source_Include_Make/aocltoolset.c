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
20-Oct-17
changes:
A help interface was added such that the user has more input for the functions inside the program.
25-Oct-17
changes committed:
Help interface was committed, although incomplete.
*/
#include "aocltoolset.h"
#include "boardConfig.h"
#include "transmission.h"
#include "compileAOCL.h"
#include "help.h"



int main() {

  char configure[10];
  int memReady = 0;

  memReady = Memcheck();
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
            helpScreen();
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
