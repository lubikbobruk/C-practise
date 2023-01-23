#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZES 10

int * evenFirst(int * arr)
{
    int copyy[SIZES]={0},amountofodd=0;
    for(int i=0;i<SIZES;i++)
    {
        copyy[i]=arr[i];
        if(copyy[i]%2)
            amountofodd++;
    }
    int j=SIZES-amountofodd,index=0;
    for(int i=0;i<SIZES;i++)
    {
        if(copyy[i]%2==0) {
            arr[index] = copyy[i];
            index++;
        }
        else
        {
            arr[j] = copyy[i];
            j++;
        }

    }
    return arr;
}


int main()
{
    int arr[SIZES]={1,2,3,4,5,6,7,8,9,10};
    evenFirst(arr);
    for(int i=0;i<SIZES;i++)
        printf("%d ",arr[i]);

}






//#define SECOND_TASK

#ifdef SECOND_TASK

#define SIZE 26

int main()
{
char * arr = (char *)calloc(SIZE,sizeof(arr));
printf("Enter your string :");
if(fgets(arr,SIZE,stdin)==NULL)
{
    puts("Invalid input.");
    return 1;
}
puts(arr);
if(strlen(arr)==SIZE-1)
    while(getchar()!='\n');
puts("Changing to a b c...");//26
char j='a';
for(int i=0;i<SIZE;i++)
{
    arr[i]=j;
    j++;
}
puts("Changed to alphabetic");
puts(arr);
}

#endif
