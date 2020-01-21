#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "straight.h"

int straight(int * cards){
  int numconsecutive = 1;
  for(int i = 0; i < 4; i++){
    if(cards[i] + 1 == cards[i+1])
      numconsecutive++;
  }
  if (numconsecutive > 4)
    return 1;
  else numconsecutive = 1;
  for(int i = 1; i < 5; i++){
    if(cards[i] + 1 == cards[i+1])
      numconsecutive++;
  }
  if (numconsecutive > 4)
    return 1;
  else numconsecutive = 1;
  for(int i = 2; i < 6; i++){
    if(cards[i] + 1 == cards[i+1])
      numconsecutive++;
  }
  if (numconsecutive < 5)
    return 0;
  return 1;
}
