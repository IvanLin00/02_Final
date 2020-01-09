#include "deck.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  for(int i = 0; i<7; i++){
    shuffle(deck);
  }
  print_list(deck);
  for(int i = 0; i< 3; i++){
    deal_card(deck);
    printf("after deal");
    print_list(deck);
  }
  return 0;
}
