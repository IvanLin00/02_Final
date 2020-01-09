struct card{
  char suit; //spade (s) > heart (h) > club (c) > diamond (d)
  int face; //num 1-13
  struct card * next; //next card
};
void print_list(struct card *);
struct card * insert_front(struct card *, int value, char s);
struct card * free_list(struct card *);
struct card * remove_card(struct card *front, int data);
void shuffle(struct card * deck);
void swap(struct card * deck, int first, int second);
