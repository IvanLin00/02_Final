struct all_cards{
  struct card hand[7];
};

int hand_type(struct hand * hand, struct flop * flop);
int flush(struct hand * hand, struct flop * flop);
struct all_cards sort_cards(struct hand * hand, struct flop * flop)
int straight(struct hand * hand, struct flop * flop)
