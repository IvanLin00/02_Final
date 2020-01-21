#include "deck.h"
#include "bets.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


// void edit_bal(int bet, char condition[100], int rounds){
//   FILE *fp;
//   char buffer[256];
//   int current_bal;
//   fp = fopen("./bets.txt", "r+");
//   lseek(FILE, 0, SEEK_CUR);
//   fgets(buffer, sizeof(buffer), fp);
//   *strchr(buffer, '\n') = 0;
//   sscanf(buffer, "%d", &current_bal);
//   if(!strcmp(condition, "win")) current_bal += bet;
//   else current_bal -= bet;
//   char *bal;
//   sprintf(bal, "%d", current_bal);
//   fprintf(fp, "%s", bal);
//   fprintf(fp, " \n");
//   printf("%d\n", current_bal);
// }

void make_bal(){
  FILE *fp;
  fp = fopen("./bets.txt", "w+");
  fprintf(fp, "200 \n");
  fclose(fp);
}
