#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"
int card_frequency[14];
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
    if(straight(hand,flop))
      return 0;
    else
     return 3;
  }
  if(isTriple(hand,flop)){
    if(isDouble(hand,flop))
      return 2;
    else
      return 5;
  }
  if(isDouble(hand,flop) == 2)
    return 6;
  if(isDouble(hand,flop))
    return 7;
  if(straight(hand,flop))
    return 4;
  if(isQuad(hand,flop))
    return 1;
  return 8;
}

int isQuad(struct hand * hand,struct flop * flop){
  struct card * cards = order(hand, flop);
  populate_freq(cards);
  int returnval = quad();
  depopulate();
  return returnval;
}

int quad(){
  for(int i = 1; i < 14; i++){
    if(card_frequency[i] == 4)
      return 1;
  }
  return 0;
}

int isTriple(struct hand * hand,struct flop * flop){
  struct card * cards = order(hand, flop);
  populate_freq(cards);
  int returnval = triple();
  depopulate();
  return returnval;
}

int triple(){
  for(int i = 1; i < 14; i++){
    if(card_frequency[i] == 3)
      return 1;
  }
  return 0;
}


int isDouble(struct hand * hand,struct flop * flop){
  struct card * cards = order(hand, flop);
  populate_freq(cards);
  int returnval = pair();
  depopulate();
  return returnval;
}

int pair(){
  int numDouble = 0;
  for(int i = 1; i < 14; i++){
    if(card_frequency[i] == 2)
      numDouble++;
  }
  return numDouble;
}

void populate_freq(struct card * card){
  for(int i = 0; i < 7; i++){
    card_frequency[card[i].face]++;
  }
}

void depopulate(){
  for(int i = 0; i < 14; i++){
    card_frequency[i] = 0;
  }
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
  int numconsecutive = 1;
  struct card * cards = order(hand,flop);
  for(int i = 0; i < 4; i++){
    if(cards[i].face + 1 == cards[i+1].face)
      numconsecutive++;
  }
  if (numconsecutive < 5)
    numconsecutive = 0;
  for(int i = 1; i < 5; i++){
    if(cards[i].face + 1 == cards[i+1].face)
      numconsecutive++;
  }
  if (numconsecutive < 5)
    numconsecutive = 0;
  for(int i = 2; i < 6; i++){
    if(cards[i].face + 1 == cards[i+1].face)
      numconsecutive++;
  }
  if (numconsecutive < 5)
    return 0;
  return 1;
}

struct card * order(struct hand * hand, struct flop * flop){
  static struct card cards[7];
  cards[0] = hand->hand[0];
  if(hand->hand[1].face < cards[0].face){
    cards[1] = cards[0];
    cards[0] = hand->hand[1];
  }
  else
   cards[1] = hand->hand[1];
  int num_inserted = 2;
  for(int n = 0; n < flop->size; n++){
    if(flop->flop[n].face >= cards[num_inserted - 1].face)
      cards[num_inserted] = flop->flop[n];
    else{
      for(int tocomp = num_inserted; tocomp > 0; tocomp--){
        while(flop->flop[n].face < cards[tocomp - 1].face){
          cards[tocomp] = cards[tocomp-1];
          cards[tocomp-1] = flop->flop[n];
        }
      }
    }
    num_inserted++;
  }
  return cards;
}

int winner(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct hand * p3_hand, struct flop * flop){
  struct hand * all[4];
  all[0] = p0_hand;
  all[1] = p1_hand;
  all[2] = p2_hand;
  all[3] = p3_hand;

  static struct winning * playerhand[4];
  struct winning * p0 = calloc(1,sizeof(struct winning));
  struct winning * p1 = calloc(1,sizeof(struct winning));
  struct winning * p2 = calloc(1,sizeof(struct winning));
  struct winning * p3 = calloc(1,sizeof(struct winning));
  playerhand[0] = p0;
  playerhand[1] = p1;
  playerhand[2] = p2;
  playerhand[3] = p3;
  for(int i = 0; i < 4; i++){
    playerhand[i]->playernum = i;
    playerhand[i]->handtype = hand_type(all[i],flop);
    printf("%d \n", playerhand[i]->handtype);
  }

  int freq = lowest(playerhand);
  int winner = 0;
  for(int i = 0; i < 4; i++){
    if(playerhand[i]->isWin ==  1)
      winner = i;
  }
  if(freq == 1)
    return winner;
  else
    return tiebreaker(playerhand);
}

int lowest(struct winning ** playerhand){
  int champIndex = 0;
  int freq = 0;
  for(int i = 1; i < 4; i++){
    if(playerhand[i]->handtype < playerhand[champIndex]->handtype)
      champIndex = i;
  }
  int wintype = playerhand[champIndex]->handtype;
  for(int i = 0; i < 4; i++){
    if(playerhand[i]->handtype == playerhand[champIndex]->handtype){
      playerhand[i]->isWin = 1;
      freq++;
    }
  }
  return freq;
}

int tiebreaker(struct winning ** playerhand){
  int win_type = 9;
  for(int i = 0; win_type==9 && i < 4; i++){
    if(playerhand[i]->isWin == 1)
      win_type = playerhand[i]->handtype;
  }
  printf("wt %d \n", win_type);
  if(win_type == 0 || win_type == 4)
    return compare_straight(playerhand);
  if(win_type == 1)
    return 11;
  if(win_type == 2)
    return 12;
  if(win_type == 3)
    return 13;
  if(win_type == 5)
    return 15;
  if(win_type == 6)
    return 16;
  if(win_type == 7)
    return 17;
  if(win_type == 8)
    return 18;
  return 4;
}

int compare_straight(struct winning ** playerhand){
  return 10;
}
