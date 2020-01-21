#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "flush.h"

int flush(struct hand * hand, struct flop * flop){
  int numsuit[2] = {1,1};
  if(hand->hand[0].suit == hand->hand[1].suit)
  numsuit[0]++;
  for(int i = 0; i < 2; i++){
    for(int n = 0; n < 5; n++){
      if(hand->hand[i].suit == flop->flop[n].suit)
        numsuit[i]++;
      if(numsuit[i] > 4)
        return 1;
    }
  }
  return 0;
}
