all: poker.o deck.o linked_list.o hand_flop.o
	gcc -o poker poker.o deck.o linked_list.o hand_flop.o

poker.o: poker.c deck.h hand_flop.h
	gcc -c poker.c

deck.o: deck.c deck.h linked_list.h
	gcc -c deck.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

hand_flop.o: hand_flop.c hand_flop.h linked_list.h
	gcc -c hand_flop.c

run:
	./poker

clean:
	rm *.o
	rm poker
