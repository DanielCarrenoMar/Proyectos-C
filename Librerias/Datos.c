#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Pide al usuario un número entero de un digito y lo devuelve.
*/
int pedirNum (char* mensaje){
    char num[10];
    char* error;

    while (1){
        printf(mensaje);
        error = fgets(num, 10, stdin);
        if (error != NULL && num[0] >= '0' && num[0] <= '9'){
            return num[0] - '0';
        }
        printf("Error al leer el numero\n");
    }
}
/*
Pide al usuario un número entero y lo devuelve.
*/
int pedirNums (char* mensaje){
    char num[10];
    char* error;

    while (1){
        printf(mensaje);
        error = fgets(num, 10, stdin);
        if (error != NULL && num[0] >= '0' && num[0] <= '9'){
            return atoi(num);
        }
        printf("Error al leer el numero\n");
    }
}
/*
    Usar un puntero al primer elemento de la matriz para modificar todos su espacios por *Valor*
*/
void limpiarMatriz(int* matriz, int x, int y, int valor){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            *(matriz + i*y + j) = valor;
        }
    }
}
/*
     Usar un puntero al primer elemento de la matriz para imprimir todos sus espacios
*/
void imprimirMatriz(int* matriz, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%d  ", *(matriz + i*y + j));
        }
        printf("\n");
    }
}