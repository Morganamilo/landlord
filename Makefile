all:
	gcc -c src/main.c -o bin/main.o
	gcc -c src/display.c -o bin/display.o
	gcc -c src/mapping.c -o bin/mapping.o
	gcc -c src/player.c -o bin/player.o
	gcc -c src/game.c -o bin/game.o
	gcc -c src/puzzles.c -o bin/puzzles.o
	gcc -c src/util.c -o bin/util.o
	gcc bin/*.o -o landlord
install:
	cp landlord /usr/local/bin/
clean:
	rm -r bin/*.o
	rm landlord
