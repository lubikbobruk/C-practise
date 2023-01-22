#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void scanArr(char * arr)
{
    puts("Enter string here :");
    if(fgets(arr,SIZE,stdin)==NULL)
        puts("Nespravny vstup.");
}

void spaceDelition(char * arr)
{
    int non_space_count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] != ' ')
        {
            arr[non_space_count] = arr[i];
            non_space_count++;
        }
    }
    arr[non_space_count] = '\0';
}


int sameElements(char * arr1,char * arr2)
{
    int answer=0;
    for(int j=0;j<strlen(arr1);j++)
        for(int i=0;i<strlen(arr2);i++)
            if(arr1[j]==arr2[i])
            {
                answer++;
                break;
            }
    if(answer==strlen(arr1))
    {
        puts("Yes,they do.");
        return 1;
    }
    else
    {
        puts("No,they do not.");
        return 0;
    }
}
void isAnagram(char * arr1,char * arr2)
{
    for(int i=0;i<strlen(arr1);i++)
    {
        arr1[i]=toupper(arr1[i]);
    }
    for(int i=0;i<strlen(arr1);i++)
    {
        arr2[i]=toupper(arr2[i]);
    }
    if(sameElements(arr1,arr2))
        puts("Yes,arr1 and arr2 are anagrams.");
    else
        puts("NO,arr1 and arr2 are not anagrams.");

}
int rotation(char * arr1,char * arr2)
{
    if(strlen(arr1)!=strlen(arr2)) {
        puts("arr1 and arr2 are not of the same size!");
        return 1;
    }
    int counter1=1,counter2=1,length=strlen(arr1)-2;
    int temp=length;
    for(int i=0;i<length;i++,temp--)// length of string without \0 and \n
    {
        if(arr1[i]!=arr2[temp])
            counter1=0;
    }
    if(counter1)
    {
        puts("Is a palindrom");
        return 0;
    }
    //second check
    int temp1=length/2;
    if(length%2!=0) {
        printf("Words are not rotated.\n");
        return 10;
    }
    for(int i=0;i<length/2;i++)
    {
        if (arr1[i]!=arr2[temp1] || arr1[temp1]!=arr2[i])
        counter2 = 0;
        temp1++;
    }
    if(counter2)
    {
        puts("Is a rotation");
        return 1;
    }
    puts("Arrays are not a palindrom nor a rotation of each other.");
    return 3;
}

int main()
{
    char arr1[SIZE],arr2[SIZE];
    scanArr(arr1);
    scanArr(arr2);
    printf("arr1: \n");
    puts(arr1);
    printf("arr2: \n");
    puts(arr2);
    //rotation(arr1,arr2);
    char arr1_no_spaces[SIZE],arr2_no_spaces[SIZE];
    strcpy(arr1_no_spaces,arr1);
    strcpy(arr2_no_spaces,arr2);
    spaceDelition(arr1_no_spaces);spaceDelition(arr2_no_spaces);
    puts("Do arr1 and arr2 store the same content?");
    sameElements(arr1_no_spaces,arr2_no_spaces);
    /*printf("arr1 w spaces - %s\narr1 wout spaces - %s\n",arr1,arr1_no_spaces);
    printf("arr2 w spaces - %s\narr2 wout spaces - %s\n",arr2,arr2_no_spaces);*/
    puts("Are arr1 and arr2 anagrams?");
    isAnagram(arr1,arr2);
}
