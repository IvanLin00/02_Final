#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "hand_flop.h"

struct hand * create_hand(struct card * deck){
  struct hand * hole = malloc(sizeof(struct hand));
  hole->hand[0] = *deck;
  hole->hand[1] = *(deck -> next);
  return hole;
}

void print_hand(struct hand * hand){
  for(int i = 0; i < 2; i++)
    print(hand->hand[i]);
  printf("\n");
}

struct flop * create_flop(struct card * deck){
  struct card * null = calloc(1,sizeof(struct card));
  struct card * deck_holder = deck;
  struct flop * flop = malloc(sizeof(struct flop));
  for(int i = 0; i < 3; i++){
    flop->flop[i] = *deck_holder;
    deck_holder = deck_holder -> next;
  }
  flop->flop[3] = *null;
  flop->flop[4] = *null;
  flop->size = 3;
  free(null);
  return flop;
}

struct flop * addto_flop(struct flop * flop, int index, struct card * deck){
  flop->flop[index] = *deck;
  flop->size++;
  return flop;
}

void print_flop(struct flop * flop){
  for(int i = 0; i < flop->size; i++)
    print(flop->flop[i]);
  printf("\n");
}
