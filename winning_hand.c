#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"
#include "straight.h"
#include "flush.h"
#include "pair.h"
#include "triple.h"
#include "quad.h"
#include "high_card.h"
int num_winners;
int * p0_cards;
int * p1_cards;
int * p2_cards;
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

void print_winners(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct flop * flop){
  print_winner(determine_winner(handtypes(p0_hand,p1_hand,p2_hand,flop)));
}

void print_winner(int * winners){
  for(int i = 0; i < num_winners; i++){
    printf("winner: player %d\n", winners[i]);
  }
}

int * determine_winner(int * pokerhands){
  int freq = 0;
  int * winners = calloc(freq,sizeof(int));
  int champIndex = min(pokerhands);
  // printf("champIndex %d \n", champIndex);
  int champValue = pokerhands[champIndex];
  for(int i = 0; i < 3; i++){
    if(pokerhands[i] == champValue){
      freq++;
      winners[freq-1] = i;
    }
  }
  num_winners = freq;
  if(freq == 1)
    return winners;
  else return tiebreakder(pokerhands, pokerhands[champIndex]);
}

int min(int * ranks){
  int champIndex = 0;
  for(int i = 1; i < 3; i++){
    if(ranks[i] < ranks[champIndex])
      champIndex = i;
  }
  return champIndex;
}

int * tiebreakder(int * pokerhands, int winning_type){
  int * winners = calloc(num_winners, sizeof(int));
  // if(winning_type = 7)
  //   return pair_breaker(pokerhands, winning_type, package, num_winners);
  return winners;
}

int * handtypes(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct flop * flop){
  create_order1(p0_hand,p1_hand,p2_hand,flop);
  int * pokerhands = calloc(3,sizeof(int));
  pokerhands[0] = handtype(p0_hand,flop);
  pokerhands[1] = handtype(p1_hand,flop);
  pokerhands[2] = handtype(p2_hand,flop);
  for(int i = 0; i < 3; i++){
    printf("player %d hand type: %d\n",i,pokerhands[i] );
  }
  return pokerhands;
}

int handtype(struct hand * hand, struct flop * flop){
  int * ordered_hand = create_order(hand,flop);
  if(flush(hand,flop)){
    if(straight(ordered_hand))    return 0;
    else                          return 3;
  }
  else if(quad(ordered_hand))     return 1;
  else if(triple(ordered_hand)){
    if(pair(ordered_hand))        return 2;
    else                          return 5;
       }
  else if(straight(ordered_hand)) return 4;
  else if(pair(ordered_hand))     return 8 - pair(ordered_hand);
  return 8;
}

int * create_order(struct hand * hand, struct flop * flop){
  int * ordered_hand = calloc(7,sizeof(int));
  ordered_hand[0] = hand->hand[0].face;
  if(hand->hand[1].face < ordered_hand[0]){
    ordered_hand[1] = ordered_hand[0];
    ordered_hand[0] = hand->hand[1].face;
  }
  else ordered_hand[1] = hand->hand[1].face;
  int num_inserted = 2;
  for(int n = 0; n < flop->size; n++){
    if(flop->flop[n].face >= ordered_hand[num_inserted - 1])
      ordered_hand[num_inserted] = flop->flop[n].face;
    else{
      for(int tocomp = num_inserted; tocomp > 0; tocomp--){
        while(flop->flop[n].face < ordered_hand[tocomp - 1]){
          ordered_hand[tocomp] = ordered_hand[tocomp-1];
          ordered_hand[tocomp-1] = flop->flop[n].face;
        }
      }
    }
    num_inserted++;
  }
  // for(int i = 0; i < 7; i++){
  //   printf("order %d\n", ordered_hand[i]);
  // }
  return ordered_hand;
}

void create_order1(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct flop * flop){
  p0_cards = create_order(p0_hand,flop);
  p1_cards = create_order(p1_hand,flop);
  p2_cards = create_order(p2_hand,flop);
}
