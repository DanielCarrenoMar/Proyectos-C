#include <stdio.h>
#include <C:\Users\EQUIPO i3\Documents\CODE\C\Proyectos-en-C\Modulos\Colorama.h>

int dimx = 3;
int dimy = 3;

void dibujar(int matriz[dimx][dimy]){
    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++){
            if (matriz[x][y] == 0){
                printf(Back_BLUE "%d" Style_RESET_ALL, matriz[x][y]);
            }
            if (matriz[x][y] == 1){
                printf(Back_LIGHTBLUE_EX "%d" Style_RESET_ALL, matriz[x][y]);
            }
            if (matriz[x][y] == 2){
                printf(Fore_BLUE "%d" Style_RESET_ALL, matriz[x][y]);
            }
            if (matriz[x][y] == 3){
                printf(Fore_LIGHTBLUE_EX "%d" Style_RESET_ALL, matriz[x][y]);
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

