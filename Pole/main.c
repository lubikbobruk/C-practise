#include <stdio.h>
#define SIZE 10

void sort(int *arr)
{
    int newarr[SIZE];
    for(int i=0;i<SIZE;i++)
        newarr[i]=arr[i];//creating a copy
    int counter=-1;
    for(int i=0;i<SIZE;i++)
    {
        if (newarr[i] % 2 == 0)
            counter++;
    }//to know the amount of even numbers
    int temp=counter+1;
    for(int i=0;i<SIZE;i++) {
        if (newarr[i] % 2 == 0)
            arr[counter--] = newarr[i];
    }
    for(int i=0;i<SIZE;i++)
    {
        if (newarr[i] % 2 != 0)
            arr[temp++] = newarr[i];
    }
}

void printArr(int arr[])
{
    for(int i=0;i<SIZE;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE]={3,4,5,1,2,2,332,-23,-12,0};
    puts("Original array:");
    printArr(arr);
    puts("Sorted array:");
    sort(arr);
    printArr(arr);
    return 0;
}
