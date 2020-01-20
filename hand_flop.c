#include "hand_flop.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct card * create_hand(struct card * deck){
  static struct card hand[2];
  hand[0] = *deck;
  hand[1] = *(deck -> next);
  return hand;
}

void print_hand(struct card * hand){
  print(hand[0]);
  print(hand[1]);
  printf("\n");
}

struct card * create_flop(struct card * deck, int num_called){
  static struct card flop[5];
  for(int i = 0; i < 3 + num_called; i++){
    flop[i] = *deck;
    deck = deck->next;
  }
}
