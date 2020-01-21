all: join_game.o make_game.o networking.o poker.o deck.o linked_list.o hand_flop.o winning_hand.o bets.o
	gcc -o join_game join_game.o networking.o poker.h deck.o linked_list.o hand_flop.o winning_hand.o bets.o
	gcc -o make_game make_game.o networking.o poker.h deck.o linked_list.o hand_flop.o winning_hand.o bets.o

poker.o: poker.c deck.h hand_flop.h
	gcc -c poker.c

bets.o: bets.c deck.h
	gcc -c bets.c

deck.o: deck.c deck.h linked_list.h
	gcc -c deck.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

hand_flop.o: hand_flop.c hand_flop.h linked_list.h
	gcc -c hand_flop.c

winning_hand.o: winning_hand.c winning_hand.h linked_list.h hand_flop.h
	gcc -c winning_hand.c

join_game.o: join_game.c networking.h
	gcc -c join_game.c

make_game.o: make_game.c networking.h
	gcc -c make_game.c

networking.o: networking.c networking.h
	gcc -c networking.c

run:
	./poker

clean:
	rm *.o
	rm ./join_game
	rm ./make_game
	rm ./bets.txt
