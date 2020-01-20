#include "deck.h"

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

void shuffle (struct card *deck){
	for (int i = 0; i < DECK_SIZE; i++)
		swap(deck, i, rand()%DECK_SIZE);
}

void swap(struct card * deck, int first, int second){
	struct card * first_holder = find_card(deck, first);
	int first_face = first_holder->face;
	char first_suit = first_holder->suit;
	struct card * second_holder = find_card(deck, second);
	int second_face = second_holder->face;
	char second_suit = second_holder->suit;
	first_holder->face = second_face;
	first_holder->suit = second_suit;
	second_holder->face = first_face;
	second_holder->suit = first_suit;
}
