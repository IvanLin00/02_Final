#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DECK_SIZE 52

struct card * deal_card(struct card * deck);
struct card * create_deck();
void shuffle(struct card * deck);
void swap(struct card * deck, int first, int second);
struct card * create_hand(struct card * deck);
