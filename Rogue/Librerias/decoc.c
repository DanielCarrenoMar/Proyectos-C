#include <windows.h>
#include <stdlib.h>
#include <stdio.h> 

void setConsoleColor(char bg, char fg){
    char cmd[30];
    sprintf(cmd, "color %c%c", bg, fg);
    system(cmd);
}

void setConsoleDim(int x, int y){
    char cmd[30];
    sprintf(cmd, "mode con: cols=%d lines=%d", x, y);
    system(cmd);
}

void gotoxy(int x, int y){ // centrar texto en la consola
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void line(int x1, int y1, int x2, int y2, char sprite, int tablero[200][200], int dibujar = 0){
    int paso;

    if (x1 == x2){
        if (y1 < y2){paso = 1;}else{paso = -1;}
        for (int i = y1; i != y2; i += paso){
            //gotoxy(x1, i);
            //printf("%c", sprite);
            tablero[i][x1] = sprite;
        }
    }else if (y1 == y2){
        if (x1 < x2){paso = 1;}else{paso = -1;}
        for (int i = x1; i != x2; i += paso){
            //gotoxy(i, y1);
            //printf("%c", sprite);
            tablero[y1][i] = sprite;
        }
    }
    else{
        float m = (float)(y2 - y1) / (x2 - x1);
        float b = y1 - m * x1;
        if (x1 < x2){paso = 1;}else{paso = -1;}
        for (int i = x1; i != x2; i += paso){
            int y = m * i + b;
            //printf("%c", sprite);
            tablero[y][i] = sprite;
        }
    }
}

void poligono(int  coords[16][2], int elemt, char sprite){
    for (int i = 0; i < elemt-1; i++){
        line(coords[i][0], coords[i][1], coords[i + 1][0], coords[i + 1][1], sprite, 0);
    }
}

void recuadro(int x, int y, int w, int h){

    for (int i = x; i < x + w; i++){
        gotoxy(i, y);
        printf("%c", 205);
        gotoxy(i, y + h);
        printf("%c", 205);
    }
    for (int i = y; i < y + h; i++){
        gotoxy(x, i);
        printf("%c", 186);
        gotoxy(x + w, i);
        printf("%c", 186);
    }
    gotoxy(x, y); printf("%c", 201);
    gotoxy(x + w, y); printf("%c", 187);
    gotoxy(x, y + h); printf("%c", 200);
    gotoxy(x + w, y + h); printf("%c", 188);
}

void hidecursor(){
    printf("\e[?25l");
}

void showcursor() {
    printf("\e[?25h");
}

void desactivarmax() {
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

