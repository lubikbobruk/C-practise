#include <stdio.h>

typedef struct
{
    int x;
    int y;
    int z;//result
}Equation;


int main()
{
    Equation first,second;
    printf("Enter 3 numbers of equation,so they will be pasted instead of *:\n*x1+*y1=*z1\n");
    printf("Format of input should be like this:\n 1 2 3\n\n");
    if(scanf("%d %d %d",&first.x,&first.y,&first.z)!=3)
    {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter 3 numbers of equation,so they will be pasted instead of *:\n*x2+*y2=*z2\n");
    printf("Format of input should be like this:\n 1 2 3\n\n");
    if(scanf("%d %d %d",&second.x,&second.y,&second.z)!=3)
    {
        printf("Invalid input.\n");
        return 2;
    }
    printf("So,here goes your 2 eqautions:\n%dx1+%dy1=%d\n%dx2+%dy2=%d\n",first.x,first.y,first.z,second.x,second.y, second.z);
    printf("\nLet`s make a matrix from them:\n%d %d | %d\n%d %d | %d\n",first.x,first.y,first.z,second.x,second.y, second.z);

    if(first.x*second.y == first.y * second.x)
    {
        printf("\nCan`t divide by zero\n%d * %d == %d * %d\nEquation does not have an answer or does have an infinite number of answers.\n",first.x,second.y,first.y,second.x);
        return 3;
    }
    int x = (first.z * second.y - first.y * second.z)/(first.x*second.y - first.y * second.x);
    int y = (first.z * second.x - first.x * second.z)/(first.x*second.y - first.y * second.x);
    printf("\nx = %d\ny = %d\n",x,y);
    return 0;
}
