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
    print_list(deal_card(deck));
  }
  return 0;
}
