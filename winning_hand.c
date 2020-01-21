#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "winning_hand.h"
#include "hand_flop.h"

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

int hand_type(struct card * hand, struct card * flop, int flopsize){
  if(flush(hand,flop,flopsize)){
    // if(straight(hand,flop,flopsize))
    //   return 0;
    // else
     return 3;
  }
  // if(two_pair(hand,flop,flopsize))
  //   return 6;
  // if(pair(hand,flop,flopsize))
  //   return 7;
  // if(straight(hand,flop,flopsize))
  //   return 4;
  // if(triple(hand,flop,flopsize)){
  //   if(house(hand,flop,flopsize))
  //     return 2;
  //   else
  //     return 5;
  // }
  // if(quad(hand,flop,flopsize))
  //   return 1;
  return 8;
}

int flush(struct card hand[2], struct card * flop, int flopsize){
  int numsuit1 = 1;
  char suit1 = hand[0].suit;
  char suit2 = hand[1].suit;
  printf("%c and %c \n",suit1, suit2);
  if(hand[0].suit == hand[1].suit){
    numsuit1++;
  }
  printf("numsuit1 %d\n", numsuit1 );
  return 1;
}
