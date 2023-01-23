#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int scanN(int * n)
{
    if(scanf("%d",n)!=1)
    {
        puts("Invalid input.");
        return 1;
    }
    return 0;
}

void scanArr(int * arr,int n,int number)
{
    int i=0;
    while(i<n)
    {
        printf("Enter %d number of an array%d:",i,number);
        scanN(&arr[i]);
        i++;
    }
}

void Intersection(int * arr1,int * arr2,int * interArr,int n1,int n2)
{
    int counter =0;
    for(int j=0;j<n1;j++)
    {
        for (int i = 0; i < n2; i++) {
            if (arr1[j] == arr2[i])
            {
                interArr[counter++]=arr1[j];
                break;
            }
        }
    }
}

void printArr(int * arr,int size,int n)
{
    printf("Here goes your array%d : [",n);
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        if(i<size-1)
            printf(",");
    }
    printf("]\n");
}
int main()
{
    int n1=0,n2=0;
    printf("Enter the size of an array1:");
    if(scanN(&n1))
        return 1;
    printf("Size of arr1 - %d\n",n1);
    printf("Enter the size of an array2:");
    if(scanN(&n2))
        return 2;
    printf("\nSize of arr2 - %d",n2);
    int * arr1 = (int *)calloc(n1,sizeof(arr1));
    int * arr2 = (int *)calloc(n2,sizeof(arr2));
    printf("\n");
    scanArr(arr1,n1,1);
    scanArr(arr2,n2,2);
    int counter =0;
    for(int j=0;j<n1;j++)
    {
        for (int i = 0; i < n2; i++) {
            if (arr1[j] == arr2[i])
            {
                counter++;
                break;
            }
        }
    }
    int * interArr = (int *)calloc(counter,sizeof(interArr));
    Intersection(arr1,arr2,interArr,n1,n2);
    printArr(arr1,n1,1);
    printArr(arr2,n2,2);
    printArr(interArr,counter,3);

}