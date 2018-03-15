#include <aocltoolset.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>



void BoardConfig() {
  FILE *fp;
  FILE *fw;
  char G1[255] = "boardnames.txt";
  char *Board_List;
  char boardName[CHUNK];
  long lSize;
  char buf[CHUNK];
  FILE *file;
  size_t nread;

  fw = fopen(G1, "w+");
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
    printf("Enter the board name to add to the configuration file.\n");
    scanf("%s", &boardName);
    fputs(boardName, fw);
    fclose(fw);

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
