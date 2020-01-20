all: poker.o deck.o linked_list.o hand_flop.o winning_hand.o
	gcc -o poker poker.o deck.o linked_list.o hand_flop.o winning_hand.o

poker.o: poker.c deck.h hand_flop.h winning_hand.h
	gcc -c poker.c

deck.o: deck.c deck.h linked_list.h
	gcc -c deck.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

hand_flop.o: hand_flop.c hand_flop.h linked_list.h
	gcc -c hand_flop.c

winning_hand.o: winning_hand.c winning_hand.h linked_list.h
	gcc -c winning_hand.c

run:
	./poker

clean:
	rm *.o
	rm poker
