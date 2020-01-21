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
  //if(flush){
    // if(straight)
    //   return 0;
    // else
     //return 3;
  //}
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
