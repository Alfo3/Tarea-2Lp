#ifndef ACCIONES_H
#define ACCIONES_H
#include "tablero.h" // Incluir la estructura Tablero
#include "inventario.h" // Incluir la estructura Ingrediente


typedef struct{
    char simbolo; // T para tabla, C para cocina, A para almacen, E para extintor
    void (*accion)(void*, int, int); // puntero a la funcion, EJ: cocinar, cortar, 
    int en_llamas; // 1 si está en llamas, 0 si no
    int turnos_inhabilitada; // Para estaciones apagadas con extintor
} Estacion; // Estructura para las estaciones del tablero

typedef struct{
    char nombre_plato[50]; // nombre del plato
    Ingrediente** ingredientes_requeridos; // Lista de ingredientes necesarios
    int completado; // 1 si fue entregado, 0 si esta pendiente
} Pedido;

void cortar(void* contexto, int x, int y); // tabla de cortar
void cocinar(void* contexto, int x, int y); // cocina
void buscar_ingrediente(void* contexto, int x, int y); // almacen
void apagar_incendio(void* contexto, int x, int y); // extintor
void entergar_pedido(void* contexto); // entrega de pedido

#endif // ACCIONES_H