#include <stdio.h>
#include <stdlib.h>

int multi(int num1, int num2);
int multi_im(int num1, int num2, int res);

int main()
{
    int num1, num2;

    printf("Numero1: ");
    scanf("%i", &num1);
    printf("Numero2: ");
    scanf("%i", &num2);
    
    printf("%i", multi(num1, num2));
}

int multi(int num1, int num2)
{
    return multi_im(num1, num2, 0);
}

int multi_im(int num1, int num2, int res)
{
    if (num1 == 0)
    {
        return res;
    }
    else
    {
        return multi_im(num1 - 1, num2, res += num2);
    }
}