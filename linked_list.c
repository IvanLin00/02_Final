#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

void print_list(struct card *n){
  printf("[ ");
  while(n != NULL){
    if(n->face == 11) printf("jack of %c | ", n->suit );
    else if(n->face == 12) printf("queen of %c | ", n->suit );
    else if(n->face == 13) printf("king of %c | ", n->suit );
    else if(n->face == 1) printf("ace of %c | ", n->suit );
    else printf("%d of %c | ", n->face, n->suit );
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

struct card * find_card(struct card *n, int index){
	struct card *find = n;
	if(index == 0) return find;
	return find_card(find->next,index - 1);
}

struct card * free_list(struct card *n){
  while(n != NULL){
    struct card *freed = n;
    n = n->next;
    free(freed);
	freed = NULL;
  }
  return n;
}


struct card * remove_front(struct card *front){
    struct card *cardToRemove = front;
    front = front->next;
    free(cardToRemove);
    return front;
}

int listsize(struct card *cards){
	if(cards == NULL) return 0;
	return 1 + listsize(cards->next);
}
