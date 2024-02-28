#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa la semilla del generador de números aleatorios
    srand(time(0));

    // Genera un número aleatorio
    int random_number = rand() % 20;

    printf("Número aleatorio: %d\n", random_number);

    return 0;
}