#ifndef INVENTARIO_H
#define INVENTARIO_H

typedef struct {
    char nombre[30]; // nombre del ingrediente
    int estado; // Ej: 0 = crudo, 1 cortado, 2 cocido, 3 quemado
    int es_extintor; // 1 si es un extintor, 0 si es ingrediente
    int turnos_elaboracion; // turnos que tarda en prepararse *CORTAR SIEMPRE DEMORA 1 TURNO*
    int prob_incendio; // probabilidad de causar incendio
} Ingrediente;

void crearInventario();
void agregarIngrediente();
void eliminarIngrediente();
void verInventario();
void liberarInventario();

#endif // INVENTARIO_H