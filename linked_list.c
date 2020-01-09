#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

#define LIST_SIZE 52

void print_list(struct card *n){
  printf("[ ");
  while(n->next != NULL){
    printf("%d of %c\n", n->face, n->suit );
    n = n->next;
  }
  printf("]\n");
}

struct card * insert_front(struct card *n, int value, char s){
	 struct card *n1 = malloc(sizeof(struct card));
	 n1 -> face = value;
	 n1 -> suit = s;
	 n1 -> next = n;
	 return n1;
}

struct card * find_node(struct card *n, int index){
	struct card *find = n;
	if(index == 0) return find;
	return find_node(find->next,index - 1);
}

void shuffle (struct card *deck){
	for (int i = 0; i < LIST_SIZE; i++)
		swap(deck, i, rand()%5);
}

void swap(struct card * deck, int first, int second){
	struct card * first_holder = find_node(deck, first);
	int first_face = first_holder->face;
	char first_suit = first_holder->suit;
	struct card * second_holder = find_node(deck, second);
	int second_face = second_holder->face;
	char second_suit = second_holder->suit;
	first_holder->face = second_face;
	first_holder->suit = second_suit;
	second_holder->face = first_face;
	second_holder->suit = first_suit;
}


// struct card * free_list(struct card *n){
// 	 struct card *freecard = n;
// 	 n = n->next;
// 	 freecard = NULL;
// 	 free(freecard);
// 	 return n;
// }
//
// struct card * remove_card(struct card *front, int data){
// 	 struct card *prev = malloc(sizeof(struct card));
// 	 struct card *n1 = malloc(sizeof(struct card));
// 	 n1 = NULL;
// 	 prev = NULL;
// 	 struct card *first = front;
// 	 while(first != NULL){
// 		 if (first-> i == data){
// 			 n1 = first;
// 			 break;
// 		 }
// 		 prev = first;
// 		 first = first-> next;
// 	 }
// 	 if (n1 != NULL){
// 		 if(prev == NULL){
// 			 front = n1 -> next;
// 		 }
// 		 else{
// 			 prev->next = n1 -> next;
// 		 }
// 		free_list(n1);
// 	 }
// 	 return front;
//
// }