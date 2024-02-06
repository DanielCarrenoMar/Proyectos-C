#include <stdio.h>

int main(){
    int i = 4;
    int* p = &i;
    int** pp = &p;
    printf("*p = %d\n", *p);
    printf("p = %d\n", p);
    printf("**pp = %d\n", **pp);
    printf("*pp = %d\n", *pp);
    printf("pp = %d\n", pp);
}