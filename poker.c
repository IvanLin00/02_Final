#include "deck.h"
#include "linked_list.h"
//#include "winning_hand.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  printf("%s\n", "original deck: ");
  print_list(deck);
  for(int i = 0; i< 26; i++){
    printf("\nhand\n");
    struct card * hand = create_hand(deck);
    print_list(hand);
    hand = free_list(hand);
    printf("\ndeck after dealing hand\n");
    print_list(deck);
  }
 return 0;
}
