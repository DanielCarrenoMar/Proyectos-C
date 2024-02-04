#include <windows.h>
#include <stdio.h>

#define SPEED 20

int main() {
    int speed;

    // Obtener la velocidad actual del mouse
    SystemParametersInfo(SPI_GETMOUSESPEED, 0, &speed, 0);
    printf("La velocidad actual del mouse es %d\n", speed);

    // Cambiar la velocidad del mouse a un valor entre 1 y 20
    int new_speed = SPEED;  // Cambia este valor para ajustar la sensibilidad
    SystemParametersInfo(SPI_SETMOUSESPEED, 0, (void*)(uintptr_t)new_speed, 0);
    printf("La nueva velocidad del mouse es %d\n", new_speed);

    // Obtener la velocidad actual del mouse
    SystemParametersInfo(SPI_GETMOUSESPEED, 0, &speed, 0);
    printf("La velocidad actual del mouse es %d\n", speed);

    return 0;
}