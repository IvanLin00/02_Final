#include "deck.h"
#include "linked_list.h"

// struct card * deal_card(struct card * deck){
// 	struct card * first = malloc(sizeof(struct card));
// 	struct card * second = malloc(sizeof(struct card));
// 	first -> face = deck -> face;
// 	first -> suit = deck -> suit;
// 	first -> next = second;
// 	second -> next = NULL;
// 	print_list(first);
// 	free(first);
// 	first = NULL;
// 	free(second);
// 	second = NULL;
// 	return first;
// }


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

struct card * create_hand(struct card *deck){
	struct card * hand = malloc(sizeof(struct card));
	int fac = find_card(deck,1)->face;
	char sui = find_card(deck,1)->suit;
	hand = insert_front(hand, deck->face,deck->suit);
	hand = insert_front(hand,fac, sui);
  *deck = *remove_front(deck);
	*deck = *remove_front(deck);
	return hand;
}
