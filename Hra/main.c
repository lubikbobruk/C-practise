#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

typedef struct
{
    int step;
    char name[SIZE];
}Player;

void printFirst(Player * arr,int n,int numberOfNumbers)
{
    int maxLength=0;
    for(int i=0;i<n;i++)
        if(strlen(arr[i].name)-1>maxLength)
            maxLength = strlen(arr[i].name)-1;
    for(int i=0;i<maxLength+11;i++)
        printf(" ");
    for(int i=0;i<numberOfNumbers;i++)
        printf("%d ",i+1);
    printf("\n");
}
int main() {
    int amountOfPlayers;
    gameRepeat:
    printf("Enter how many players should there be in the game(must be >=2):");
    if (scanf("%d", &amountOfPlayers) != 1 || amountOfPlayers < 2) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    Player *listOfPlayers = (Player *) malloc(amountOfPlayers * sizeof(*listOfPlayers));
    int n = 4 * amountOfPlayers;
    int *places = (int *) calloc(n, sizeof(places));
    printf("Amount of Players : %d\n", amountOfPlayers);
    getchar();
    for (int i = 0; i < amountOfPlayers; i++) {
        memset(listOfPlayers[i].name, '\0', sizeof(SIZE));
        printf("Enter the name for Player %d:", i + 1);
        if (fgets(listOfPlayers[i].name, SIZE, stdin) == NULL) {
            puts("Invalid input.");
            return 2;
        }
    }
    puts("\n\t----------------------------\n\t\tGame Started\n\t----------------------------");
    int winner = 0, reset = 1;
    char onceAgain;
    while (winner != 1) {
        for (int i = 0; i < amountOfPlayers; i++) {
            alreadyChosen:
            printf("Player %.*s ,choose a step: ", strlen(listOfPlayers[i].name) - 1, listOfPlayers[i].name);
            if (scanf("%d", &listOfPlayers[i].step) != 1 || listOfPlayers[i].step > n || listOfPlayers[i].step < 0) {
                puts("Invalid input.");
                return 3;
            }
            if (places[(listOfPlayers[i].step) - 1] == 1) {
                puts("You can not choose already chosen number.\nTry again.");
                goto alreadyChosen;
            }
            places[(listOfPlayers[i].step) - 1] = 1;
            printFirst(listOfPlayers, amountOfPlayers, n);
            printf("PLayer %.*s => ", strlen(listOfPlayers[i].name) - 1, listOfPlayers[i].name);
            int j = 0;
            for (int i = 0; i < (n * 2) + 1; i++) {
                if (i % 2 == 0) {
                    printf("|");
                    continue;
                }
                if (places[j] == 1) {
                    printf("X");
                    j++;
                    continue;
                }
                if (places[j] == 0)
                    printf(" ");
                j++;
            }
            printf("\n");
            int winCounter = 0;
            for (int i = 0; i < n; i++)//checking if there is a combo and a winne
            {
                if (places[i] == 1)
                    winCounter++;
                if (places[i] == 0)
                    winCounter = 0;
                if (winCounter >= 3) {
                    winner = 1;
                    reset = 0;
                    break;
                }
            }
            if (winner == 1) {
                puts("\t\tGAME OVER");
                printf("--------------------------------------------\n");
                printf("Player %.*s just won,Congratulations!\n", strlen(listOfPlayers[i].name) - 1,
                       listOfPlayers[i].name);
                printf("--------------------------------------------\n");
                break;
            }

            if (i == amountOfPlayers - 1 && reset)
                i = -1;
        }
        //NEW GAME?
        puts("Dou you want to play again?\nPress any button to continue.");
        puts("To quit, press q");
        if (scanf(" %c",&onceAgain)!=1) {
            puts("I didn`t get it,mate :(\nBye!");
        }
        else {
            if(onceAgain == 'q' || onceAgain == 'Q')
                return 0;
            for (int i = 0; i < n; i++)
                places[i] = 0;
            winner = 0;
            reset = 1;
            char empty[SIZE]={"\0"};;
            for(int i=0;i<amountOfPlayers;i++)
            {
                strncpy(listOfPlayers[i].name,empty,SIZE);
            }
            goto gameRepeat;
        }
    }
}


/*  * create list of players with specified n
 * step fucntion
 * print first function
 *check who won
 * game should end only if someone won
 * if step is out of range,enter again
 */