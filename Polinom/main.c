#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int areEqual(char * arr1,char * arr2,int n)
{
    if (strncmp(arr1,arr2,n)==0)
        return 1;
    else
        return 0;
}
void reverse(char * newarr,int length)
{
    char temp[length+1];
    strncpy(temp,newarr,length);
    printf("temp - %s",temp);
    for(int i=0;i<length-1;i++)  //              temp={'r','u','n','\n','\0'}   newarr={'n','u','r','\n','\0','\0',...} strlen= 4
    {
        newarr[i] = temp[length - i - 2];
    }
}




int main()
{
    int n;
    printf("Enter the size of a string: ");
    if(scanf("%d",&n) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    getchar();//removes newline from the buffer!!!
    n++;

    char *arr=(char *)calloc(n,sizeof(arr));
    printf("Enter a string : ");
    if(fgets (arr, n, stdin)==NULL)
        return 2;
    puts(arr);

    printf("Enter a second string : ");

    char *newarr = (char*)calloc(n,sizeof(arr));
    if(fgets (newarr, n, stdin)==NULL)
        return 3;
    puts(newarr);
    puts("Reversing...");
    if(strlen(newarr)==strlen(arr))
        reverse(newarr,strlen(newarr));
    else {
        puts("strings are not of the same height!\n");
        return 4;
    }
    puts(newarr);
    printf("Are %s and %s equal?\n",arr,newarr);


    printf("\nstrlen arr - %d\n",strlen(arr));
    printf("\nstrlen newarr - %d\n",strlen(newarr));
    if(areEqual(arr, newarr,strlen(arr)))
        puts("yes");
    else
        puts("no");

    free(arr);
    free(newarr);

    return 0;

}

