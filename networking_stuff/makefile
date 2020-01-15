forking: make_game fserver

select: sclient sserver

sserver: select_server.o networking.o
	gcc -o server select_server.o networking.o

fserver: forking_server.o networking.o
	gcc -o server forking_server.o networking.o

sclient: select_client.o networking.o
	gcc -o client select_client.o networking.o

make_game: make_game.o networking.o
	gcc -o make_game make_game.o networking.o

select_client.o: select_client.c networking.h
	gcc -c select_client.c

make_client.o: make_client.c networking.h
	gcc -c make_client.c

select_server.o: select_server.c networking.h
	gcc -c select_server.c

forking_server.o: forking_server.c networking.h
	gcc -c forking_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
	rm *~
