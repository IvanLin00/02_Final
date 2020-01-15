game_setup: main_server.o networking.o join_game.o networking.o make_game.o networking.o
	gcc -o main_server main_server.o networking.o
	gcc -o join_game join_game.o networking.o
	gcc -o make_game make_game.o networking.o

make_game.o: make_game.c networking.h
	gcc -c make_game.c

main_server.o: main_server.c networking.h
	gcc -c main_server.c

join_game.o: join_game.c networking.h
	gcc -c join_game.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
	rm *~
