#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "triple.h"
#include "populate.h"

int triple(int * cards){
  populate_freq(cards);
  for(int i = 1; i < 14; i++){
  if(card_frequency[i] == 3)
    return 1;
  }
  depopulate();
  return 0;
}
