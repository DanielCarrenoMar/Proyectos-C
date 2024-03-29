/*
Pide al usuario un número entero y lo devuelve.
*/
int pedirNum (char* mensaje){
    char num[10];
    char* error;

    while (1){
        printf(mensaje);
        error = fgets(num, 10, stdin);
        if (error != NULL && num[0] >= '0' && num[0] <= '9'){
            return num[0] - '0';
        }
        printf(Fore_RED "Error al leer el numero %s \n" Style_RESET_ALL, num);
    }
}
/*
Pide al usuario una cadena de caracteres utilizando memoria dinamica y la devuelve.
*/
char* pedirCadena(char* mensaje){
    char buffer[100];
    char* str;
    char* error;

    while (1){
        printf(mensaje);
        error = fgets(buffer, 100, stdin);
        if (error != NULL)
            break;
        printf("Error al leer la cadena\n");
    }

    str = malloc(strlen(buffer) + 1);
    if (str == NULL){
        printf("Error al reservar memoria\n");
        exit(1);
    }

    strcpy(str, buffer);
    return str;
}
/*
    Usar un puntero al primer elemento de la matriz para modificar todos su espacios por *Valor*
*/
void limpiarMatriz(int* matriz, int x, int y, int valor){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            *(matriz + i*y + j) = valor;
        }
    }
}
/*
     Usar un puntero al primer elemento de la matriz para imprimir todos sus espacios
*/
void imprimirMatriz(int* matriz, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            printf("%d ", *(matriz + i*y + j));
        }
        printf("\n");
    }
}
/*
    Borra la pantalla
*/
void borrarPantalla(){
    system(CLEAR);
}
#ifdef _WIN32

/*
    Mueve el Cursor a una posicion especifica WINDOWS
*/
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

#else

/*
    Mueve el Cursor a una posicion especifica LINUX
*/
void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);
}

#endif
