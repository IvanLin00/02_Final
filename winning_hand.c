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
  return 0;
  //idea combine hand and flop into a single array, sort the array, then compare the numbers in adjacent index to see is its +-1
}

struct all_cards sort_cards(struct hand * hand, struct flop * flop){
  int hand_index = 0;
  int flop_index = 0;
  struct all_cards all = malloc(sizeof(struct all_cards));

  for(int cards_index = 0; cards_index < 7; cards_index ++){
    if (cards_index < 5){
      all[cards_index] = hand[hand_index];
      hand_index ++;
    }
    else{
      all[cards_index] = flop[flop_index];
      flop_index ++;
    }
  }
  struct all_cards sorted_array = malloc(sizeof(struct all_cards));
  int highest_index = 0;
  for(int sorted_index = 0; sorted_index < 7 ; sorted_index ++){
    for(int index = 0; index < 7; index ++){
      if(all[index] > all[highest_index]) highest_index = index;
    }
    sorted_array[sorted_index] = all[highest_index];
    all[highest_index].face = 0;
    highest_index = 0;
  }
  return sorted_array;
}
