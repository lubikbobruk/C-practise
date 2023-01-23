#include <stdio.h>
#define SIZE 2

int scanMatrix(int arr[][SIZE])
{
    printf("Fulfil the matrix:\n");
    for(int j=0;j<SIZE;j++)
        for(int i=0;i<SIZE;i++)
        {
            printf("arr[%d][%d] =", j, i);
            if (scanf(" %d", &arr[j][i]) != 1) {
                printf("Invalid input\n");
                return 0;
            }
        }
    return 1;
}
int scaleMatrix(int arr[][SIZE])
{
    int scale;
    printf("Enter the scaler value here:");
    if(scanf("%d",&scale)!=1)
    {
        puts("Invalid input.");
        return 0;
    }
    for (int j = 0; j < SIZE; j++)
        for (int i = 0; i < SIZE; i++)
            arr[j][i]*=scale;
    return 1;
}

void printMatrix(int arr[][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
            printf("%d ",arr[j][i]);
        printf("\n");
    }
}
int main() {
    int arr[SIZE][SIZE];
    if(!scanMatrix(&arr[SIZE]))
        return 1;
    printMatrix(&arr[SIZE]);
    scaleMatrix(&arr[SIZE]);
    printMatrix(&arr[SIZE]);
    /*to add to matrix,firstly:
     * we need to initialize second one and fulfil it with scan function i have writen
     * after that,create new empty matrix
     * then,we need to create new function with 3 arguments,one of which(newone)will be a matrix of sum
     * in 2 loops we will write something like this:
     * arrSum[j][i]==arr1[j][i]+arr[j][i]
     * that`s it
    */

    /*Deteminant function isn`t that hard to create
     * the problem is,that either we have to come up with an algorithm for determinant of a scale N>=3
     * or we have to do 2 function for N=2 N=3,but other N`s will not be valid for this operation
     * so I won`t do algorithm nor 2 functions :)
     *
     */
     return 0;
}
