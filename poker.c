#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"
#include "bets.h"
#include "poker.h"

int main(){
  srand(time(NULL));
  struct card * deck = create_deck();
  //printf("%s\n", "original deck: ");
  print_list(deck);
  make_bal();
  edit_bal(100,"lose", 1);
  edit_bal(100,"lose", 2);
  edit_bal(100,"win", 3);
  for(int i = 0; i< 1; i++){
/*----------------------------------------------------------------------
 testing making 4 player hands*/
    printf("\nhands\n");

//hand of player 1
    struct hand * p0_hand = create_hand(deck);
    print_hand(p0_hand);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 2
    struct hand * p1_hand = create_hand(deck);
    print_hand(p1_hand);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 3
    struct hand * p2_hand = create_hand(deck);
    print_hand(p2_hand);
    deck = remove_front(deck);
    deck = remove_front(deck);

//hand of player 4
    struct hand * p3_hand = create_hand(deck);
    print_hand(p3_hand);
    deck = remove_front(deck);
    deck = remove_front(deck);
    printf("\n");
/*----------------------------------------------------------------------
 testing making the 5 cards on the table */
    printf("flop\n");

    struct flop * flop = create_flop(deck);
  //  print_flop(flop);

    deck = remove_front(deck);
    deck = remove_front(deck);
    deck = remove_front(deck);

    addto_flop(flop,flop->size,deck);
    deck = remove_front(deck);
  //  print_flop(flop);

    addto_flop(flop,flop->size,deck);
    deck = remove_front(deck);
    print_flop(flop);
    printf("\n");
    print_winners(p0_hand,p1_hand,p2_hand,flop);
/*----------------------------------------------------------------------
 testing the deck after all the cards dealt */
  //  printf("dealt cards from deck\n");
  //  print_list(deck);
}
 return 0;
}
// void run_game(){
//   srand(time(NULL));
//   while(1){
//     //what the server does
//     struct card * deck = create_deck();
//     struct hand * p0_hand = create_hand(deck);
//     struct hand * p1_hand = create_hand(deck);
//     struct hand * p2_hand = create_hand(deck);
//     struct hand * p3_hand = create_hand(deck);
//     //send hands to players
//
//     //the player
//     //printf("%s\n", "Your hand");
//     //print_hand(hand);
//   }
// }
