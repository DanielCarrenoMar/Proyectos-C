#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librerias/utilities.h"
#include "librerias/Colorama.h"

#define LONG 2

int main (){
	borrarPantalla();
	float notas[LONG];
	float mayor = 0;
	float menor = 20;
	float prome = 0;
	
	gotoxy(18,3); printf(Style_BRIGHT "Sistema de notas" Style_RESET_ALL);
	
	for (int i = 0; i<LONG; i++){
		while(1){
		gotoxy(4,5); printf("Igresar nota del alumno %d: " Style_BRIGHT , i+1);
		gotoxy(31,5); scanf("%f", &notas[i]);
		
		gotoxy(3,5); printf(Style_RESET_ALL "                                              ");
		
		if (notas[i] > 0 && notas[i] <= 20)
			break;
			
		gotoxy(4,6); printf(Fore_RED "Error" Style_RESET_ALL);
		}
		gotoxy(3,6); printf(Style_RESET_ALL "                                              ");
	}
	
	for (int i = 0; i<LONG; i++){
		prome += notas[i];
		if (notas[i] > mayor)
			mayor = notas[i];
		if (notas[i] < menor)
			menor = notas[i];
	}
	prome = prome / LONG;
	
	for (int i = 0; i<LONG; i++){
		gotoxy(4,5); printf("NOTAS:");
		gotoxy(4,6+i); printf("nota %d: %f", i+1, notas[i]);
		gotoxy(16,6+i); printf("     ");
		
		gotoxy(36,5); printf("PROMEDIO:");
		gotoxy(36,6); printf("%f", prome);
		gotoxy(40,6); printf("     ");
		
		gotoxy(36,8); printf("MAYOR:");
		gotoxy(36,9); printf("%f", mayor);
		gotoxy(40,9); printf("     ");
		
		gotoxy(36,11); printf("MENOR:");
		gotoxy(36,12); printf("%f", menor);
		gotoxy(40,12); printf("     ");
	}
	
	gotoxy(0,0);
}
