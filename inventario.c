#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

Ingrediente* inventario = NULL;

void crearInventario(){
    inventario = (Ingrediente*)malloc(sizeof(Ingrediente)*5); // espacio de 5 ingredientes
    for (int i = 0; i < 5; i++){
        inventario[i].estado = 0;
        inventario[i].es_extintor = 0;
        inventario[i].turnos_elaboracion = 0;
        inventario[i].prob_incendio = 0;
    }
}
void agregarIngrediente(){

}
void eliminarIngrediente(){

}
void verInventario(){
    printf("****INVENTARIO****\n");
    for (int i = 0; i < 5; i++){
        if (inventario[i].nombre[0] != '\0'){
            printf("Ingrediente %d: %s\n", i+1, inventario[i].nombre);
            printf("Estado: %d\n", inventario[i].estado);
            printf("Es extintor: %d\n", inventario[i].es_extintor);
            printf("Turnos de elaboracion: %d\n", inventario[i].turnos_elaboracion);
            printf("Probabilidad de incendio: %d\n", inventario[i].prob_incendio);
        }
    }
    printf("******************\n");
}

void liberarInventario(){
    free(inventario); // Liberar la memoria del inventario
    inventario = NULL; // Evitar puntero colgante
} 