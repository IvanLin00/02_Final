#define DECK_SIZE 26

struct card * deal_card(struct card * deck);
struct card * create_deck();
void shuffle(struct card * deck);
void swap(struct card * deck, int first, int second);
