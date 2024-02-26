#define Alto 40
#define Ancho 100

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

void dibujarPlayer( int tablero[Alto][Ancho], int posx, int posy){
    for(int y = 0; y < Alto; y++){
        for(int x = 0; x < Ancho; x++){
            if (tablero[y][x] == 2){
                gotoxy(x+posx,y+posy); printf("%c", 1);
                return;
            }
        }
    }
}

int randRange(int min, int max){
    return rand() % (max - min + 1) + min;
}

void generarmazmorra(int tablero[Alto][Ancho], int x, int y, int puente){
    int ancho = randRange(2, 3);
    int alto = randRange(2, 2);
    int direccion;

    for (int i = 0; i<=ancho; i++){
        if (tablero[y+alto][x+i] != 0 
        || tablero[y+alto][x-i] != 0 
        || tablero[y-alto][x+i] != 0 
        || tablero[y-alto][x-i] != 0){return;}
    }
    for (int i = 0; i<alto; i++){
        if (tablero[y+i][x+ancho] != 0 
        || tablero[y-i][x+ancho] != 0 
        || tablero[y+i][x-ancho] != 0 
        || tablero[y-i][x-ancho] != 0){return;}
    }

    for (int i = 0; i<=ancho; i++){
        tablero[y+alto][x+i] = 1;
        tablero[y+alto][x-i] = 1;
        tablero[y-alto][x+i] = 1;
        tablero[y-alto][x-i] = 1;
    }
    for (int i = 0; i<alto; i++){
        tablero[y+i][x+ancho] = 1;
        tablero[y-i][x+ancho] = 1;
        tablero[y+i][x-ancho] = 1;
        tablero[y-i][x-ancho] = 1;
    }

    if(puente == 1){
        tablero[y][x+ancho] = 0;
    }else if(puente == 2){
        tablero[y][x-ancho] = 0;
    }else if(puente == 3){
        tablero[y+alto][x] = 0;
    }else if(puente == 4){
        tablero[y-alto][x] = 0;
    }

    do{
        direccion = rand() % 4 +1;
    } while (direccion == puente);


    if(direccion == 1){
        tablero[y][x+ancho] = 0;
        if (x+ancho*2+2 > Ancho){return;}
        if (tablero[y+1][x+ancho+2] != 0){return;}
        generarmazmorra(tablero, x+ancho*2+2, y, 2);
    }else if(direccion == 2){
        tablero[y][x-ancho] = 0;
        if (x-ancho*2-2 < 0){return;}
        if (tablero[y+1][x-ancho-2] != 0){return;}
        generarmazmorra(tablero, x-ancho*2-2, y, 1);
    }else if(direccion == 3){
        tablero[y+alto][x] = 0;
        if (y+alto*2+2 > Alto){return;}
        if (tablero[y+alto*2+2][x+1] != 0){return;}
        generarmazmorra(tablero, x, y+alto*2+2, 4);
    }else if(direccion == 4){
        tablero[y-alto][x] = 0;
        if (y-alto*2-2 < 0){return;}
        if (tablero[y-alto*2-2][x+1] != 0){return;}
        generarmazmorra(tablero, x, y-alto*2-2, 3);
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
    setConsoleDim(110, 45);
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
    generarmazmorra(tablero, Ancho/2, Alto/2, 0);
    dibujarPantalla(tablero, 5, 2);

    while(1){
        borrarPantalla(tablero, 5, 2);

        gotoxy(0,0); printf("%d  , %d  ", player[0], player[1]);

        inputPlayer(tablero, player);
        crearPlayer(tablero, player, 2);
        dibujarPlayer(tablero, 5, 2);
        
        Sleep(100);

    }

    return 0;
}