#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
#include "inventario.h"
#include "acciones.h"

typedef struct{
    Tablero* tablero; // puntero a la estructura Tablero
    Ingrediente** inventario; // puntero a la matriz de ingredientes
    Pedido* pedido; // puntero a la estructura Pedido
    int turnos_restantes; 
    int dificultad; // dificultad del juego

} Juego;

typedef struct{
    int x; // coordenada x en el tablero
    int y; // coordenada y en el tablero
    int en_llamas; // 0 si no está en llamas, 1 si está en llamas (por atravesar estacion en llamas)
    char simbolo; // simbolo del jugador
} Jugador;

void iniciarJuegoDificultad(Juego* juego); // Inicializa el juego con la dificultad seleccionada

#endif // MAIN_H