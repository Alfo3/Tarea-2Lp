Juego: main.o tablero.o inventario.o acciones.o
	gcc -o CorrerJuego main.o tablero.o inventario.o acciones.o -Wall

main.o: main.c 
	gcc -c main.c

tablero.o: tablero.c
	gcc -c tablero.c

inventario.o: inventario.c
	gcc -c inventario.c

acciones.o: acciones.c
	gcc -c acciones.c

clean:
	rm *.o CorrerJuego