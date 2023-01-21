#include <stdio.h>
#include <stdlib.h>
//#define FIRST_TASK
//#define SECOND_TASK
//#define THIRD_TASK
#ifdef FIRST_TASK
int main()
{
 int n;
 printf("Please enter a size of array");
 if(scanf("%d",&n)!=1)
     return 1;
 int* array = calloc(n,sizeof(*array));
 for(int i=0;i<n;i++)
     printf("%d",array[i]);
free(array);
    return 0;
}
#endif

#ifdef SECOND_TASK
int main()
{
    int n;
    printf("Please enter a size of array");
    if(scanf("%d",&n)!=1)
        return 1;
    int* array =malloc(n*sizeof(*array));
    for(int i=0;i<n;i++)
    {
        array[i] = i+1;
        printf("%d ", array[i]);
    }

    return 0;
}
#endif

#ifdef THIRD_TASK

int main()
{
    int a,n;
    printf("Please enter a size of an array.\n");
    if(scanf("%d",&n)!=1){
        printf("Invalid input.\n");
        return 1;}
    printf("Enter the value of the first element of an array.\n");
    if(scanf("%d",&a)!=1) {
        printf("Invalid input.\n");
        return 2;
    }


    int* array =malloc(n*sizeof(*array));
    for(int i=0;i<n;i++,a++)
    {
        array[i] = a;
        printf("%d ", array[i]);
    }

    return 0;
}
#endif

