#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "linked_list.h"
#include "hand_flop.h"
#include "winning_hand.h"
#include "bets.h"
#include "run_game.h"

 void run_game(){
  srand(time(NULL));
  while(1){
    //what the server does
    struct card * deck = create_deck();
    struct hand * p0_hand = create_hand(deck);
    struct hand * p1_hand = create_hand(deck);
    struct hand * p2_hand = create_hand(deck);
    struct hand * p3_hand = create_hand(deck);
    //send hands to players

    //the player
    //printf("%s\n", "Your hand");
    //print_hand(hand);
  }
}
