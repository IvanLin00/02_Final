int * handtypes(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct flop * flop);
int handtype(struct hand * hand, struct flop * flop);
int * create_order(struct hand * hand, struct flop * flop);
void create_order1(struct hand * p0_hand, struct hand * p1_hand, struct hand * p2_hand, struct flop * flop);
void print_winner(int * winners);
int * determine_winner(int * pokerhands);
int * tiebreakder(int * pokerhands, int winning_type);
int min(int * ranks);
void print_winners(struct hand * p0_hand, struct hand * p1_hand, struct hand * p3_hand, struct flop * flop);
