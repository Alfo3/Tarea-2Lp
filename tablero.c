#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
#include "main.h"

void inicializar_tablero(Tablero* tablero, int filas, int columnas) {
    tablero->filas = filas;
    tablero->columnas = columnas;
    tablero->celdas = (void***)malloc(filas * sizeof(void**));
    for (int i = 0; i < filas; i++){
        tablero->celdas[i] = (void**)malloc(columnas * sizeof(void*));
        for (int j = 0; j < columnas; j++){
            tablero->celdas[i][j] = NULL; // Inicializa las celdas a NULL
        }
    }
}


void mostrar_tablero(Tablero* tablero){
    for (int i = 0; i < tablero->filas; i++){
        for (int j = 0; j < tablero->columnas; j++){
            void* celda = tablero->celdas[i][j];
            if (celda == NULL){
                printf("[ ]");
            }
            else{ 
                Jugador* elemento = (Jugador*)celda;
                if (elemento->simbolo) { // Si es un jugador
                    printf("[%c]", elemento->simbolo);
                }
                else {
                    Estacion* estacion = (Estacion*)celda;
                    printf("[%c]", estacion->simbolo);
                }
            }
        }
    printf("\n");
    }
}

void encontrar_jugador(Tablero* tablero, void* elemento) {
    // Primero: actualizar coordenadas del jugador si existe en el tablero
    for (int i = 0; i < tablero->filas; i++) {
        for (int j = 0; j < tablero->columnas; j++) {
            void* celda = tablero->celdas[i][j];
            if (celda != NULL) {
                Jugador* posible_jugador = (Jugador*)celda;
                // Verificamos si tiene el símbolo de un jugador
                if (posible_jugador->simbolo == 'O') {
                    posible_jugador->x = i;
                    posible_jugador->y = j;
                }
            }
        }
    }
}

void actualizar_celdas(Tablero* tablero, int x, int y, void* elemento){
    // Actualiza la celda en la posición (x, y) con el nuevo elemento
    if (x >= 0 && x < tablero->filas && y >= 0 && y < tablero->columnas) {
        tablero->celdas[x][y] = elemento;
    } else {
        printf("Coordenadas fuera de los limites del tablero\n");
    }
}


void liberar_tablero(Tablero* tablero) {
    if (tablero == NULL || tablero->celdas == NULL) {
        return; // No hay nada que liberar
    }
    for (int i = 0; i < tablero->filas; i++){
        free(tablero->celdas[i]);
    }
    free(tablero->celdas);
    tablero->celdas = NULL;
}

void randomizar_tablero(Tablero* tablero, void* elemento){
    int x, y;
    do {
        x = rand() % tablero->filas;
        y = rand() % tablero->columnas;
    } while (tablero->celdas[x][y] != NULL);
    tablero->celdas[x][y] = elemento;
}