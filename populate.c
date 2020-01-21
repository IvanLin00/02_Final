#include "linked_list.h"
#include "populate.h"

void populate_freq(int * cards){
  for(int i = 0; i < 7; i++){
    card_frequency[cards[i]]++;
  }
}

void depopulate(){
  for(int i = 0; i < 14; i++){
    card_frequency[i] = 0;
  }
}
