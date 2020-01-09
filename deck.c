#include "deck.h"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DECK_SIZE 52

struct card * create_deck(){
	struct card * first = malloc(sizeof(struct card));
	int face_value = 1;
	char suit = 'd';
	for(int i = 0; i < DECK_SIZE; i++){
		first = insert_front(first, face_value, suit);
		face_value++;
		if(face_value == 14){
			if(suit == 's') break;
			if(suit == 'h') suit = 's';
			if(suit == 'c') suit = 'h';
			if(suit == 'd') suit = 'c';
			face_value = 1;
		}
	}
	shuffle(first);
	return first;
}
