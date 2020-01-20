#include "deck.h"
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  printf("%s\n", "original deck: ");
  print_list(deck);
  for(int i = 0; i< 4; i++){
/*----------------------------------------------------------------------
 testing making 4 player hands*/
    printf("\nhands\n");

//hand of player 1
    struct card * p1_hand = create_hand(deck);
    print_hand(p1_hand,2);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 2
    struct card * p2_hand = create_hand(deck);
    print_hand(p2_hand,2);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 3
    struct card * p3_hand = create_hand(deck);
    print_hand(p3_hand,2);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 4
    struct card * p4_hand = create_hand(deck);
    print_hand(p4_hand,2);
    deck = remove_front(deck);
    deck = remove_front(deck);
    printf("\n");
/*----------------------------------------------------------------------
 testing making the 5 cards on the table */
    printf("flop\n");

    struct card * flop = create_flop(deck);
    print_hand(flop,5);

    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);

    addto_flop(flop,3,deck);
    deck = remove_front(deck);
    print_hand(flop,5);

    addto_flop(flop,4,deck);
    deck = remove_front(deck);
    print_hand(flop,5);
    printf("\n");
/*----------------------------------------------------------------------
 testing the deck after all the cards dealt */
    printf("dealt cards from deck\n");
    print_list(deck);
  }
 return 0;
}
