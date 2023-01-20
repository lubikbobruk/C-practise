#include <stdio.h>

void pyramidPrint(int n)
{
    int times=1;
    for(int i=0;i<n;i++)//rows
    {
        for(int j=i;j<n-1;j++)
            printf(" ");
        for(int j=0;j<times;j++)
            printf("*");
        times+=2;
        printf("\n");
    }
}
int main()
{
    int n;
    if(scanf("%d",&n)!=1)
    {
        printf("Invalid input.\n");
        return 0;
    }
    pyramidPrint(n);

}
