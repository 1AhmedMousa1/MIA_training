#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    printf("Enter your number: ");
    scanf("%d", &num1);
    while(num1>0){
    printf("%d\n", num1);
    num1--;
    }
    printf("Blast off to the moon");
    return 0;
}
