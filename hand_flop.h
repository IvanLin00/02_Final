struct hand{
  struct card hand[2];
};

struct flop{
  struct card flop[5];
  int size;
};
struct hand * create_hand(struct card * deck);
void print_hand(struct hand * hand);
struct flop * create_flop(struct card * deck);
struct flop * addto_flop(struct flop * flop, int index, struct card * deck);
void print_flop(struct flop * flop);
