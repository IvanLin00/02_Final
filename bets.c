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
  int fd = open("./bets.txt", O_CREAT | O_TRUNC | O_RDWR);
  if (fd < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }
  int initial_bal[4];
  initial_bal[0] = 0;
  initial_bal[1] = 2;
  initial_bal[2] = 0;
  initial_bal[3] = 0;

  int wd = write(fd, &initial_bal, sizeof(initial_bal));
  if (wd < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }
  //for testing
  int curr_bal[4];
  int rd = read(fd, &curr_bal, sizeof(curr_bal));
  for(int i = 0; i < 4; i++){
    printf("%d\n", curr_bal[i]);
  }
  //done testing
  int cld = close(fd);
  if (cld < 0){
    printf("error %d: %s\n", errno, strerror(errno));
    return;
  }
}
