#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"

/*
straight flush: 0
four of a kind: 1
full house: 2
flush: 3
straight: 4
Three of a kind: 5
two pair: 6
one pair: 7
high card: 8
*/

int hand_type(struct hand * hand, struct flop * flop){
  if(flush(hand,flop)){
    // if(straight)
    //   return 0;
    // else
     return 3;
  }
  // if(two_pair)
  //   return 6;
  // if(pair)
  //   return 7;
  // if(straight)
  //   return 4;
  // if(triple){
  //   if(house)
  //     return 2;
  //   else
  //     return 5;
  // }
  // if(quad)
  //   return 1;
  return 8;
}

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

int straight(struct hand * hand, struct flop * flop){
  //idea combine hand and flop into a single array, sort the array, then compare the numbers in adjacent index to see is its +-1
}
