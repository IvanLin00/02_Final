#include "deck.h"
#include "bets.h"

void edit_bal(int bet, char condition[100]){
  int current_bal, new_bal;

  int fd = open("./bets.h", O_RDWR);
  if (fd < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }

  int rd = read(fd, &current_bal, sizeof(current_bal));
  if (rd < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }

  if(!strcmp(condition,"win")) new_bal = current_bal + bet;
  else new_bal = current_bal - bet;
  int wd = write(fd, &new_bal, sizeof(new_bal));
  if (wd < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }

  int cld = close(fd);
  if (cld < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }
}

void make_bal(){
  FILE *fp;
  fp = fopen("./bets.txt", "w+");
  fputs("200\n", fp);
  printf("%d \n",fgetc(fp));
  fclose(fp);
}
