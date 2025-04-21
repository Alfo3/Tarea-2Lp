#ifndef TABLERO_H
#define TABLERO_H

typedef struct {
    void*** celdas; //matriz 2d de elementos
    int filas; //numero de filas
    int columnas; //numero de columnas
} Tablero;

void inicializar_tablero(Tablero* tablero, int filas, int columnas);
void mostrar_tablero(Tablero* tablero);
void actualizar_tablero(Tablero* tablero, int x, int y, void* elemento);
void liberar_tablero(Tablero* tablero);
void randomizar_tablero(Tablero* tablero, void* elemento);

#endif // TABLERO_H