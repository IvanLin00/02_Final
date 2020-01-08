#include "deck.h"
#include <stdlib.h>
#include <stdio.h>

#define DECK_SIZE 5

int main(){
	int * deck = malloc(5 * sizeof(int));
	for(int i = 0; i < 5; i++)
		deck[i] = 3 + i;
	for(int i =0; i < 5; i++)
		printf("hi[%d]\n", deck[i]);
	printf("did it work\n");
	shuffle(deck);
	printf("yes\n");
	for(int i =0; i < 5; i++)
		printf("[%d]\n", deck[i]);

	return 0;
}

void shuffle (int deck[DECK_SIZE]){
	for (int i = 0; i < DECK_SIZE; i++)
		swap(deck, deck[i], DECK_SIZE * deck[3/*rand num from 0 to 1 multiply by deck size*/]);
}

void swap(int deck[DECK_SIZE], int first, int second){
	int holder = deck[second];
	deck[second] = deck[first];
	deck[first] = holder;
}

