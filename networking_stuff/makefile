game_setup: networking.o join_game.o networking.o make_game.o networking.o
	gcc -o join_game join_game.o networking.o
	gcc -o make_game make_game.o networking.o

make_game.o: make_game.c networking.h
	gcc -c make_game.c

join_game.o: join_game.c networking.h
	gcc -c join_game.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
	rm join_game
	rm main_server
	rm make_game
