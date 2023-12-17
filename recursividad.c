#include <stdio.h>

long fact(long num)
{
    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
}

int main()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    for(int i = 0; i <= num; i++)
    {
        printf("%d! = %ld\n", i, fact(i));
    }
    return 0;
}

