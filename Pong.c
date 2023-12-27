#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define H 21
#define W 75

enum dibujo {
    PLAYER1 = '1',
    PLAYER2 = '2',
    BALL = 'O'
};

//Funciones

void crear(char tablero[H][W], int initjug1[2], int initjug2[2], int pospel[2]);
void dibujar(char tablero[H][W]);
void bucle(char tablero[H][W], int pospel[2], int initjug1[2], int initjug2[2], int modpel[2]);
void input(char tablero[H][W], int pospel[2], int initjug1[2], int initjug2[2], int modpel[2], int *punto);

int main (){
    
    int pospel[2], initjug1[2], initjug2[2];
    int modpel[2];
    char tablero[H][W];

    //posiciones
    pospel[0] = 37;
    pospel[1] = 10;
    
    initjug1[0] = 8;
    initjug1[1] = 12;

    initjug2[0] = 8;
    initjug2[1] = 12;

    //Modificaciones
    modpel[0] = 1;
    modpel[1] = 1;

    crear(tablero, initjug1, initjug2, pospel);
    bucle(tablero, pospel, initjug1, initjug2, modpel);

    //system("pause");
    return 0;
}

void crear(char tablero[H][W], int initjug1[2], int initjug2[2], int pospel[2]){
    int i, j;
    for (i=0; i<H; i++){
        for (j=0; j<W; j++){
            //Bordes
            if (i==0 || i==H-1){
                tablero[i][j] = '-';
            }
            else if (j==0 || j==W-1){
                tablero[i][j] = '|';
            }
            else{
                tablero[i][j] = ' ';
            }

            //Jugadores
            if (i>=initjug1[0] && i<=initjug1[1]){
                if (j==2 || j==3){
                    tablero[i][j] = PLAYER1;
                }
            }
            if (i>=initjug2[0] && i<=initjug2[1]){
                if (j==W-4 || j==W-3){
                    tablero[i][j] = PLAYER2;
                }
            }

            //Pelota
            if (i==pospel[1] && j==pospel[0]){
                tablero[i][j] = BALL;
            }
        }
    }
}

void dibujar(char tablero[H][W]){
    system("cls");
    int i, j;
    for (i=0; i<H; i++){
        for (j=0; j<W; j++){
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

void bucle(char tablero[H][W], int pospel[2], int initjug1[2], int initjug2[2], int modpel[2]){
    int punto = 0;
    
    do{
        dibujar(tablero);
        input(tablero, pospel, initjug1, initjug2, modpel, &punto);
        crear(tablero, initjug1, initjug2, pospel);
        Sleep(10);
    }while (punto == 0);
}

void input(char tablero[H][W], int pospel[2], int initjug1[2], int initjug2[2], int modpel[2], int *punto){
    char key;


    if (pospel[1] == 1 || pospel[1] == H-2){
        modpel[1] *= -1;
    }

    if (pospel[0] == 1 || pospel[0] == W-2){
        *punto += 1;
    }

    if (pospel[0] == 4 || pospel[0] == 3){
        if (pospel[1] >= initjug1[0] && pospel[1] <= initjug1[1]){
            modpel[0] *= -1;
        }
    }

    if (pospel[0] == W-5 || pospel[0] == W-4){
        if (pospel[1] >= initjug2[0] && pospel[1] <= initjug2[1]){
            modpel[0] *= -1;
        }
    }

    if (*punto == 0){
        pospel[0] += modpel[0];
        pospel[1] += modpel[1];
    }
    
    if (kbhit() == 1){
        key = getch();

        if (key == 'w'){
            if (initjug1[0] > 1){
                initjug1[0] -= 1;
                initjug1[1] -= 1;
            }
        }
        else if (key == 's'){
            if (initjug1[1] < H-2){
                initjug1[0] += 1;
                initjug1[1] += 1;
            }
        }
        else if (key == 'i'){
            if (initjug2[0] > 1){
                initjug2[0] -= 1;
                initjug2[1] -= 1;
            }
        }
        else if (key == 'k'){
            if (initjug2[1] < H-2){
                initjug2[0] += 1;
                initjug2[1] += 1;
            }
        }
    }
}