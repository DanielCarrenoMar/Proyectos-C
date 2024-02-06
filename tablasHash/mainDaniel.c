#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct  tabla{
    int espacio;
    int espacioVacio;
    char** llave; 
    char** valor;
} tabla_t;

tabla_t* crearHash(int cantidad);
int eliminarHash(tabla_t** tabla);
int agregaElemento(char* llave, char* valor, tabla_t* tabla);
int imprimirHash(tabla_t* tabla);
int sumaAscii(char *str);
char* accederHash(tabla_t *tabla, char* llave);

int main(){

    tabla_t* tabla;

    tabla = crearHash(10);

    agregaElemento("hola", "mundooo", tabla);
    agregaElemento("hole", "planeta", tabla);
    agregaElemento("adios", "casa", tabla);

    imprimirHash(tabla);

    printf("%s", accederHash(tabla, "hola"));

    eliminarHash(&tabla);

    return 0;
}

tabla_t* crearHash(int cantidad){
    tabla_t* tempTabla;

    tempTabla = malloc(sizeof(tabla_t));
    if (tempTabla == NULL){
        return NULL;
    }

    tempTabla->espacio = cantidad;
    tempTabla->espacioVacio = cantidad;

    tempTabla->llave = calloc(cantidad, sizeof(char*));
    if (tempTabla->llave == NULL){
        eliminarHash(&tempTabla);
        return NULL;
    }

    tempTabla->valor = calloc(cantidad, sizeof(char*));
    if (tempTabla->valor == NULL){
        eliminarHash(&tempTabla);
        return NULL;
    }

    return tempTabla;
}

int eliminarHash(tabla_t** tabla){
    if (tabla == NULL || *tabla == NULL){
        return -1;
    }

    int cantidad = (*tabla)->espacio;
    for (int i=0; i<cantidad; i++) {
        free((*tabla)->valor[i]);
    }

    free((*tabla)->llave);
    free((*tabla)->valor);
    free(*tabla);

    return 0;
}

int agregaElemento(char* llave, char* valor, tabla_t* tabla){
    
    if (tabla == NULL){
        return -1;
    }

    if (tabla->espacioVacio <= 0){
        return -1;
    }

    int index = sumaAscii(llave) % tabla->espacio;
    if (tabla->llave[index] == NULL){
        tabla->llave[index] = strdup(llave);
        tabla->valor[index] = strdup(valor);
        tabla->espacioVacio--;
    }
    else{
        int newindex = index;

        while(1){
            newindex = (newindex + 1) % tabla->espacio;
            if (tabla->llave[newindex] == NULL){
                tabla->llave[newindex] = strdup(llave);
                tabla->valor[newindex] = strdup(valor);
                tabla->espacioVacio--;
                break;
            }
        }
    }
    return 0;
}

int imprimirHash(tabla_t* tabla){
    if (tabla == NULL){
        return "Tabla no existe";
    }

    int cantidad = tabla->espacio;

    printf("Index \t\t Key \t\t Value\n");
    for (int i=0; i<cantidad; i++) {
        if (tabla->llave[i] == NULL) {
        printf("%d \n", i);
        }
        else {
        printf("%d \t\t %s \t\t %s\n", i, tabla->llave[i], tabla->valor[i]);
        }
    
    }
    return 0;
}

char* accederHash(tabla_t *tabla, char* llave){
    if (tabla == NULL){
        return -1;
    }

    int index = sumaAscii(llave) % tabla->espacio;

    return tabla->valor[index];
}

int sumaAscii(char *str) {
    int sum = 0;
    while (*str) {
        sum += *str;
        str++;
    }
    return sum;
}