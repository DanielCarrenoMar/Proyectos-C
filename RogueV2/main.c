#define Alto 30
#define Ancho 40

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "librerias/decoc.h"

void crearPlayer( int tablero[Alto][Ancho], int* player, int id){
    int x = player[0];
    int y = player[1];

    tablero[y][x] = id;
}

void inputPlayer( int tablero[Alto][Ancho],int* player){
    int x = player[0];
    int y = player[1];

    tablero[y][x] = 0;


    if (kbhit()){
        char key = getch();

        if (key == 'w' && tablero[y-1][x] == 0){
            player[1] -= 1;
        }
        if (key == 's' && tablero[y+1][x] == 0){
            player[1] += 1;
        }
        if (key == 'a' && tablero[y][x-1] == 0){
            player[0] -= 1;
        }
        if (key == 'd' && tablero[y][x+1] == 0){
            player[0] += 1;
        }
    }

    if (player[0] < 0){ player[0] = 0; }
    else if (player[0] > Ancho-1){ player[0] = Ancho-1;}
    else if (player[1] < 0){ player[1] = 0; }
    else if (player[1] > Alto-1){ player[1] = Alto-1;}
}

void crearCasa( int tablero[Alto][Ancho], int x, int y, int ancho, int alto){
    if (x < 0 || x > Ancho || y < 0 || y > Alto){
        return;
    }
    for(int i = -1; i < alto+1; i++){
        for(int j = -1; j < ancho+1; j++){
            if (tablero[y+i][x+j] != 0){
                return crearCasa(tablero, rand() % 20, rand() % 20, ancho, alto);
                }
        }
    }

    for(int i = 0; i < alto; i++){
        for(int j = 0; j < ancho; j++){
            if(i == 0 || i == alto-1){
                tablero[y+i][x+j] = 1;
            }else if(j == 0 || j == ancho-1){
                tablero[y+i][x+j] = 1;
            }else{
                tablero[y+i][x+j] = 0;
            }
        }
    }
}

void dibujarPantalla( int tablero[Alto][Ancho], int posx, int posy){
    
    for(int y = 0; y < Alto; y++){
        for(int x = 0; x < Ancho; x++){
            if(tablero[y][x] == 1){
                gotoxy(x+posx,y+posy); printf("#");
            }
            else if (tablero[y][x] == 2){
                gotoxy(x+posx,y+posy); printf("%c", 1);
            }
        }
    }
}

void borrarPantalla( int tablero[Alto][Ancho], int posx, int posy){
    for(int i = 0; i < Alto; i++){
        for(int j = 0; j < Ancho; j++){
            if(tablero[i][j] != 0 && tablero[i][j] != 1){
                gotoxy(j+posx,i+posy); printf(" ");
            }
        }
    }
}

int main(){
    setConsoleDim(100, 40);
    setConsoleColor('0','F');
    hidecursor();
    srand(time(0));

    int tablero[Alto][Ancho];

    for(int i = 0; i < Alto; i++){
        for(int j = 0; j < Ancho; j++){
            tablero[i][j] = 0;
        }
    }

    int player[2] = {15,5};
    for (int i = 0; i < 8; i++){
        crearCasa(tablero, rand() % 20, rand() % 20, 5, 5);
    }
    while(1){
        borrarPantalla(tablero, 30, 8);

        gotoxy(0,0); printf("%d  , %d  ", player[0], player[1]);

        inputPlayer(tablero, player);
        crearPlayer(tablero, player, 2);

        dibujarPantalla(tablero, 30, 8);
        Sleep(100);

    }

    return 0;
}