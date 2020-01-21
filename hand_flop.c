#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "hand_flop.h"

struct card * create_hand(struct card * deck){
  static struct card hand[2];
  hand[0] = *deck;
  hand[1] = *(deck -> next);
  return hand;
}

void print_hand(struct card * hand, int num){
  for(int i = 0; i < num; i++)
    print(hand[i]);
  printf("\n");
}

struct card * create_flop(struct card * deck){
  struct card * null = calloc(1,sizeof(struct card));
  struct card * deck_holder = deck;
  static struct card flop[6];
  for(int i = 0; i < 3; i++){
    flop[i] = *deck_holder;
    deck_holder = deck_holder -> next;
  }
  flop[3] = *null;
  flop[4] = *null;
  flop[5].face = 3;           //flop[5] stores the size
  free(null);
  return flop;
}

struct card * addto_flop(struct card * flop, int index, struct card * deck){
  flop[index] = *deck;
  flop[5].face++;
  return flop;
}
