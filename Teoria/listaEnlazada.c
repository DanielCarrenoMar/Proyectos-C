#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <signal.h>
#include "../librerias/Colorama.h"

typedef struct snodo{
    int valor;
    struct snodo *sig;
}tnodo;

typedef tnodo* tpuntero;

tpuntero cabeza = NULL;

void delConsola();

int pedirValor();
void addNode(tpuntero *cabeza, int e);
void delLastNode(tpuntero *cabeza);
void printLista(tpuntero cabeza);
void delLista(tpuntero *cabeza);

int main (){
    just_fix_windows_console();
    
    int opcion = 0;
    
    while (1)
    {   
        delConsola();

        printLista(cabeza);

        printf("1. Ingresar un valor\n");
        printf("2. Borrar ultimo elemento \n");
        printf("3. Salir \n");
        printf("Ingrese opccion: \n");

        opcion = pedirValor();

        if (opcion == 1){
            printf("Ingrese un valor: ");
            addNode(&cabeza, pedirValor());
        }
        else if (opcion == 2){
            delLastNode(&cabeza);
        }
        else if (opcion == 3)
        {
            exit(0);
        }
    }

    delLista(&cabeza);
    printf("lista borrada");
    return 0;
}

void delConsola(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int pedirValor(){
    char entrada[10];
    char* result = fgets(entrada, 10, stdin);
    while (1){
        if (result == NULL){
            delLista(&cabeza);
            printf("Erro IO \n");
            exit(1);
        }
        if (entrada[0] > '0' || entrada[0] < '9'){
            return entrada[0] - '0';
        }
        printf(Fore_RED "Debe ingresar un valor valido\n" Style_RESET_ALL);
    }
}

void addNode(tpuntero *cabeza, int e){
    tpuntero nuevo;
    nuevo = malloc(sizeof(tnodo));
    nuevo->valor = e;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}

void delLastNode(tpuntero *cabeza){
    tpuntero temp;
    if (*cabeza == NULL){return;}
    temp = *cabeza;
    *cabeza = (*cabeza)->sig;
    free(temp);
}

void printLista(tpuntero cabeza){
    while (cabeza != NULL)
    {
        printf("%4d", cabeza->valor);
        cabeza = cabeza->sig;
    }
    printf("\n");
}

void delLista(tpuntero *cabeza){
    tpuntero temp;
    while (*cabeza != NULL)
    {
        temp = *cabeza;
        *cabeza = (*cabeza)->sig;
        free(temp);
    }
}