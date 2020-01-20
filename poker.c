#include "deck.h"
#include "linked_list.h"
#include "hand_flop.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  printf("%s\n", "original deck: ");
  print_list(deck);
  for(int i = 0; i< 4; i++){
    printf("\nhands\n");

    struct card * p1_hand = create_hand(deck);
    print_hand(p1_hand);

    struct card * p2_hand = create_hand(deck);
    print_hand(p2_hand);

    struct card * p3_hand = create_hand(deck);
    print_hand(p3_hand);

    struct card * p4_hand = create_hand(deck);
    print_hand(p4_hand);

    struct card * flop = create_flop(deck,0);

    printf("remove cards from deck\n");
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);
    print_list(deck);
  }
 return 0;
}
