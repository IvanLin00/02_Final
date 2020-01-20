struct card * create_hand(struct card * deck);
void print_hand(struct card * hand, int num);
struct card * create_flop(struct card * deck);
struct card * addto_flop(struct card * flop, int index, struct card * deck);
