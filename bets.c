#include "deck.h"
#include "bets.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void edit_bal(int bet, char condition[100], int round){
  char buffer[256];
  int current_bal;
  int fd = open("./bets.txt", O_RDWR);
  int offset = 3 * (round - 1);
  int l = lseek(fd, offset, SEEK_SET);
  printf("%d\n",l);
  int rd = read(fd, buffer, sizeof(buffer));
  *strchr(buffer,'\n') = 0; //nulling the new line
  sscanf(buffer, "%d", &current_bal);
  if(!strcmp(condition, "win")) current_bal += bet;
  else current_bal -= bet;
  printf("%d\n", current_bal);
  char bal[256];
  sprintf(bal, "%d", current_bal);
  strcat(bal, "\n");
  int wd = write(fd, bal, sizeof(bal));
  int cld = close(fd);
}

void make_bal(){
  FILE *fp;
  fp = fopen("./bets.txt", "w+");
  fprintf(fp, "200 \n");
  fclose(fp);
}
