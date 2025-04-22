#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "acciones.h"

//compilacion cd .. 3 veces, luego cd mnt/c/Users/Alfo/Desktop/LP/Tarea2 gcc -o juego main.c tablero.c inventario.c acciones.c -Wall
// luego de la compilacion ./juego

void iniciarJuegoDificultad(Juego* juego){
    int filas = 0, columnas = 0, turnos = 0, pedidos = 0;
    if (juego->dificultad == 1){
        filas = columnas = 5;
        turnos = 60;
        pedidos = 3;
    }else if (juego->dificultad == 2){
        filas = columnas = 8;
        turnos = 50;
        pedidos = 4;
    }
    else if (juego->dificultad == 3){
        filas = columnas = 10;
        turnos = 45;
        pedidos = 5;
    }
    else{
        printf("Dificultad no valida, por defecto se elegira facil\n");
        filas = columnas = 5;
        turnos = 60;
        pedidos = 3;
    }
    juego->tablero = (Tablero*)malloc(sizeof(Tablero)); // Asignar memoria para el tablero
    inicializar_tablero(juego->tablero, filas, columnas);
    juego->turnos_restantes = turnos;
    juego->pedido = (Pedido*)malloc(sizeof(Pedido) * pedidos); // Asignar memoria para los pedidos
}

int main(){
    Juego juego;
    int dificultad;

    printf("Seleccione la dificultad (1: Facil, 2: Intermedio, 3: Dificil): ");
    scanf("%d", &dificultad);
    juego.dificultad = dificultad;

    iniciarJuegoDificultad(&juego);
    
    srand(time(NULL));
    Jugador* jugador = (Jugador*)malloc(sizeof(Jugador));
    jugador->en_llamas = 0;
    jugador->simbolo = 'O';
    randomizar_tablero(juego.tablero, jugador);
    encontrar_jugador(juego.tablero, jugador);
    Estacion* tabla_cortar = (Estacion*)malloc(sizeof(Estacion));
    tabla_cortar->simbolo = 'T';
    randomizar_tablero(juego.tablero, tabla_cortar);
    Estacion* cocina = (Estacion*)malloc(sizeof(Estacion));
    cocina->simbolo = 'C';
    randomizar_tablero(juego.tablero, cocina);
    Estacion* almacen = (Estacion*)malloc(sizeof(Estacion));
    almacen->simbolo = 'A';
    randomizar_tablero(juego.tablero, almacen);
    Estacion* extintor = (Estacion*)malloc(sizeof(Estacion));
    extintor->simbolo = 'E';
    randomizar_tablero(juego.tablero, extintor);
    
    /*
    //ingredientes
    Ingrediente papa = {"Papa", 0, 0, 4, 0.02}; // crudo, cortado en 1 turno, 2% probabilidad de incendio
    Ingrediente pollo = {"Pollo", 0, 0, 5, 0.05}; // crudo, 5 turnos para cocinar, 5% probabilidad de incendio
    Ingrediente hamburguesa = {"Hamburguesa", 0, 0, 3, 0.03}; // cruda, 3 turnos para cocinar, 3% probabilidad de incendio
    Ingrediente arroz = {"Arroz", 0, 0, 2, 0.01}; // crudo, 2 turnos para cocinar, 1% probabilidad de incendio
    Ingrediente pasta = {"Pasta", 0, 0, 2, 0.01}; // cruda, 2 turnos para cocinar, 1% probabilidad de incendio
    Ingrediente tomate = {"Tomate", 0, 0, 1, 0.0}; // crudo, 1 turno para cortar
    Ingrediente lechuga = {"Lechuga", 0, 0, 1, 0.0}; // cruda, 1 turno para cortar
    Ingrediente pan = {"Pan", 0, 0, 0, 0.0}; // no necesita preparación
    Ingrediente extintor_item = {"Extintor", 0, 1, 0, 0.0}; // extintor, no necesita preparación
    Ingrediente* ingredientes[7] = {&papa, &pollo, &hamburguesa, &arroz, &pasta, &tomate, &lechuga, &pan, &extintor_item};

    // Pedidos 
    Pedido mcCharly = {"El McCharly", {&papa, &pollo, &papa}, 0};


    */
    char opcion;
    while (juego.turnos_restantes > 0){
        printf("\nTurnos restantes: %d\n", juego.turnos_restantes);
        mostrar_tablero(juego.tablero);
        printf("Seleccione una accion:\n");
        printf("1. Mover (W, A, S, D)\n");
        printf("2. Accion\n");
        printf("3. ver inventario\n");
        printf("4. Entregar pedido\n");
        printf("5. Salir\n");
        scanf(" %c", &opcion);
        if (opcion == 'W' || opcion == 'A' || opcion == 'S' || opcion == 'D') {
            int movimiento;
            printf("Casillas a mover hacia %s\n", 
                   (opcion == 'W') ? "arriba" :
                   (opcion == 'S') ? "abajo" :
                   (opcion == 'A') ? "la izquierda" : "la derecha");
            scanf("%d", &movimiento);
        
            int nueva_x = jugador->x;
            int nueva_y = jugador->y;
        
            if (opcion == 'W') nueva_x -= movimiento;
            else if (opcion == 'S') nueva_x += movimiento;
            else if (opcion == 'A') nueva_y -= movimiento;
            else if (opcion == 'D') nueva_y += movimiento;
        
            // Validar límites del tablero
            if (nueva_x >= 0 && nueva_x < juego.tablero->filas &&
                nueva_y >= 0 && nueva_y < juego.tablero->columnas) {
        
                juego.tablero->celdas[jugador->x][jugador->y] = jugador->debajo; // Celda anterior
                jugador->debajo = juego.tablero->celdas[nueva_x][nueva_y]; // Guardar celda debajo
                jugador->x = nueva_x;
                jugador->y = nueva_y;

                if (jugador->simbolo == 'O'){
                    jugador->simbolo = 'V';
                }

                juego.tablero->celdas[jugador->x][jugador->y] = jugador;
        
                juego.turnos_restantes--;
            } else {
                printf("Movimiento fuera de los limites\n");
            }
        }
        else if (opcion == '2'){
            printf("ejecutar accion a implementar\n");
        }
        else if (opcion == '3'){
            printf("ver inventario a implementar\n");
        }
        else if (opcion == '4'){
            printf("entregar pedido a implementar\n");
        }
        else if (opcion == '5'){
            printf("Saliendo del juego...\n");
            break;
        }
    }


    liberar_tablero(juego.tablero);
    free(tabla_cortar);
    free(cocina);
    free(almacen);
    free(extintor);
    free(jugador);
    free(juego.tablero);
    free(juego.pedido);
    return 0;
}
