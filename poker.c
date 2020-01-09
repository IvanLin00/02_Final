#include "deck.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  print_list(deck);
  for(int i = 0; i< 3; i++){
    printf("after deal\n");
    //deal_card(deck);      dont know why this doesnt work
    struct card *cardToRemove = deck;
    deck = deck->next;
    free(cardToRemove);
    print_list(deck);
  }
  return 0;
}
