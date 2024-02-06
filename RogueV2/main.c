#include <stdio.h>
#include "librerias/decoc.h"

#define Alto 20
#define Ancho 40

void crearPlayer(short unsigned int tablero[Alto][Ancho], int* player, int id){
    int x = player[0];
    int y = player[1];

    tablero[y][x] = id;
}

void inputPlayer(int* player){
    if (kbhit()){
        char key = getch();

        if (key == 'w'){
            player[1] -= 1;
        }
        if (key == 's'){
            player[1] += 1;
        }
        if (key == 'a'){
            player[0] -= 1;
        }
        if (key == 'd'){
            player[0] += 1;
        }
    }

    if (player[0] < 0){ player[0] = 0; }
    else if (player[0] > Ancho-1){ player[0] = Ancho-1;}
    else if (player[1] < 0){ player[1] = 0; }
    else if (player[1] > Alto-1){ player[1] = Alto-1;}
}

void crearCasa(short unsigned int tablero[Alto][Ancho], int x, int y, int ancho, int alto){
    if (x < 0 || x > Ancho || y < 0 || y > Alto){
        return;
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

void dibujarPantalla(short unsigned int tablero[Alto][Ancho], int posx, int posy){
    
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

void borrarPantalla(short unsigned int tablero[Alto][Ancho], int posx, int posy){
    for(int i = 0; i < Alto; i++){
        for(int j = 0; j < Ancho; j++){
            if(tablero[i][j] != 0){
                gotoxy(j+posx,i+posy); printf(" ");
            }
        }
    }

    for (int i = 0; i < Alto; i++){
        for (int j = 0; j < Ancho; j++){
            tablero[i][j] = 0;
        }
    }
}

int main(){
    setConsoleDim(100, 40);
    setConsoleColor('0','F');
    hidecursor();

    short unsigned int tablero[Alto][Ancho];

    for(int i = 0; i < Alto; i++){
        for(int j = 0; j < Ancho; j++){
            tablero[i][j] = 0;
        }
    }

    int player[2] = {3,3};

    while(1){
        borrarPantalla(tablero, 30, 8);
        crearCasa(tablero, 5, 5, 10, 10);

        gotoxy(0,0); printf("%d  , %d  ", player[0], player[1]);

        crearPlayer(tablero, player, 2);
        inputPlayer(player);

        dibujarPantalla(tablero, 30, 8);
        Sleep(100);

    }

    return 0;
}