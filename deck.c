#include "deck.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DECK_SIZE 5

struct card * create_deck(){
	struct card * first = malloc(sizeof(struct card));
	int face_value = 1;
	char suit = 'd';
	for(int i = 0; i < DECK_SIZE; i++){
		first = insert_front(first, face_value, suit);
		if(face_value == 13){
			if(suit == 's') break;
			if(suit == 'h') suit = 's';
			if(suit == 'c') suit = 'h';
			if(suit == 'd') suit = 'c';
			face_value = 1;
		}
	}
	//shuffle();
	return first;
}

void shuffle (int deck[DECK_SIZE]){
	for (int i = 0; i < DECK_SIZE; i++)
		swap(deck, i, rand()%5);
}

void swap(int deck[DECK_SIZE], int first, int second){
	int holder = deck[second];
	deck[second] = deck[first];
	deck[first] = holder;
}
