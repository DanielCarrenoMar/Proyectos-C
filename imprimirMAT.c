#include <stdio.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T         "\x1b[31m"
#define ROJO_F         "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T     "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T         "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T      "\x1b[35m"
#define MAGENTA_F      "\x1b[45m"
#define CYAN_T         "\x1b[36m"
#define CYAN_F         "\x1b[46m"
#define BLANCO_T       "\x1b[37m"
#define BLANCO_F       "\x1b[47m"

int dimx = 3;
int dimy = 3;

void dibujar(int matriz[dimx][dimy]){
    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++){
            if (matriz[x][y] == 0){
                printf(BLANCO_F "%d" RESET_COLOR, matriz[x][y]);
            }
            if (matriz[x][y] == 1){
                printf(ROJO_F "%d" RESET_COLOR, matriz[x][y]);
            }
            if (matriz[x][y] == 2){
                printf(VERDE_F "%d" RESET_COLOR, matriz[x][y]);
            }
            
        }
        printf("\n");
    }
}

int main() {
    int x, y;
    int mat[dimx][dimy];

    for (x=0;x<3;x++){
        for (y=0;y<3;y++){
            printf("Ingrese el valor de la posicion [%d][%d]: ",x,y);
            scanf("%d",&mat[x][y]);
        }
    } 
    dibujar(mat);
}

