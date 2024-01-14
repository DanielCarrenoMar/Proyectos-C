#include "Modulos/decoc.h"
#include "Modulos/Colorama.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h> 



int main() {
    setConsoleDim(160, 30);
    setConsoleColor('0', 'f');

    int coords[8][2] = {{3, 2}, {32, 2}, {32, 16}, {16, 16}, {16, 8}, {3, 8}, {3, 2}};
    printf(Fore_RED);
    poligono(coords, 7, 219);

    int coords2[8][2] = {{40, 10},{50, 20}};
    int coords3[8][2] = {{40, 20},{50, 10}};
    poligono(coords2, 2, 219);
    poligono(coords3, 2, 219);

    int coords4[10][2] = {{60, 5},{60, 20},{70, 20},{70, 15},{75, 15},{75, 10},{70, 10},{70, 5},{60, 5}};
    poligono(coords4, 9, 219);

    printf(Fore_BLUE);
    gotoxy(10, 2); printf("H");	
    printf(Fore_GREEN);

    int juX = 10, juY = 10;
    char key;

    while (1)
    {   
        gotoxy(juX, juY); printf("%c", 153);

        key = getch();

        if (key == 'd'){
            gotoxy(juX, juY); printf(" ");
            ++juX;
        }
        else if (key == 'a'){
            gotoxy(juX, juY); printf(" ");
            --juX;
        }
        else if (key == 'w'){
            gotoxy(juX, juY); printf(" ");
            --juY;
        }
        else if (key == 's'){
            gotoxy(juX, juY); printf(" ");
            ++juY;
        }

    }
    

    gotoxy(50, 29); system("pause");
    return 0;
}