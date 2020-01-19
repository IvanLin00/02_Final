all: poker.o deck.o linked_list.o
	gcc -o poker poker.o deck.o linked_list.o

main.o: main.c deck.h
	gcc -c main.c

deck.o: deck.c deck.h linked_list.h
	gcc -c deck.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

run:
	./poker

clean:
	rm *.o
	rm poker
