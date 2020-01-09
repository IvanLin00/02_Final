#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

void print_list(struct card *n){
  printf("[ ");
  while(n->next != NULL){
    printf("%d of %c | ", n->face, n->suit );
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




// struct card * free_list(struct card *n){
// 	 struct card *freecard = n;
// 	 n = n->next;
// 	 freecard = NULL;
// 	 free(freecard);
// 	 return n;
// }
//
struct card * remove_front(struct card *front){
    struct card *cardToRemove = front;
    front = front->next;
    free(cardToRemove);
    return front;
}
