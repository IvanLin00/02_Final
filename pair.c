#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "pair.h"
#include "populate.h"

int pair(int * cards){
  populate_freq(cards);
  int returnval = numpairs();
  depopulate();
  return returnval;
}

int numpairs(){
  int numDouble = 0;
  for(int i = 1; i < 14; i++){
    if(card_frequency[i] == 2)
      numDouble++;
  }
  return numDouble;
}
