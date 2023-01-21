#include <stdio.h>

int Fibonacci(int cycles)
{
    int first=1,second=1,current;
    printf("1 1 ");
    for(int i=0;i<cycles-1;i++)
    {
        current = first + second;
        printf("%d ",current);
        first =second;
        second = current;

    }

}

int main()
{
    Fibonacci(10);

}
