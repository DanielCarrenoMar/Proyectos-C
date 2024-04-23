#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

typedef struct vuelo
{
    char avion[20];
    char origen[20];
    char destino[20];
    int pasajeros;
}vuelo_t;

void llenarAero(vuelo_t* list, size_t tam){
    char aviones[3][20] = {"Boing","Cohete SpaceX","Caza A4"};
    char lugares[15][20] = {"Paris", "London", "New York", "Tokyo", "Rome", "Berlin", "Sydney", "Moscow", "Cairo", "Rio de Janeiro", "Amsterdam", "Toronto", "Dubai", "Seoul", "Mumbai"};
    int temp1, temp2;

    for (size_t i = 0; i<tam; i++){
        while (1){
            temp1 = rand() % 15;
            temp2 = rand() % 15;
            if (temp2 != temp1) break;
        }
        strcpy(list->avion, aviones[rand() % 3]);
        strcpy(list->origen, lugares[temp1]);
        strcpy(list->destino, lugares[temp2]);
        list->pasajeros = rand() % 100;
        list++;
    }
}
void imprimirVuelo(vuelo_t* list, size_t tam){
    for (size_t i = 0; i<tam; i++){
        printf("------- %d -------\n", i+1);
        printf(" ----------------\n");
        printf("- Modelo: %s\n", list->avion);
        printf("- Origen: %s\n", list->origen);
        printf("- Destino: %s\n", list->destino);
        printf("- Pasajeros: %d\n", list->pasajeros);
        printf(" ----------------\n");
        list++;
    }
}
void remplazarValores(vuelo_t* buffer, const char* avion, const char* origen, const char* destino, const int pasajeros){
    strcpy(buffer->avion, avion);
    strcpy(buffer->origen, origen);
    strcpy(buffer->destino, destino);
    buffer->pasajeros = pasajeros;
}
int vueloPorOrigen(vuelo_t* list, size_t tam, vuelo_t* buffer, char* origen){
    int cant = 0;
    for (size_t i = 0; i<tam; i++){
        if (strcmp(list->origen, origen) == 0){
            remplazarValores(buffer, list->avion, list->origen, list->destino, list->pasajeros);
            buffer++;
            cant++;
        }
        list++;
    }
    if (cant == 0){
        return 0;
    }
    return cant;
}

int main(){
    srand(time(NULL));
    vuelo_t* aereo = malloc(sizeof(vuelo_t)*N);
    vuelo_t* buffer = malloc(sizeof(vuelo_t)*N);
    llenarAero(aereo, N);

    imprimirVuelo(aereo, N);

    int cant = vueloPorOrigen(aereo, N, buffer, "Paris");
    printf("\n");
    printf(" -----------------------------\n");
    printf("-------- Vuelos a Paris -------\n");
    printf(" -----------------------------\n");
    if (cant == 0) printf("- No se encontrado\n");
    else{
        for(int i = 0; i<cant; i++){
        printf("- %s\n", (buffer+i)->avion);
        printf("- %s\n", (buffer+i)->origen);
        printf("- %s\n", (buffer+i)->destino);
        printf("- %d\n", (buffer+i)->pasajeros);
        printf("------------------\n");
        }
    }

    free(aereo);

    return 0;
}