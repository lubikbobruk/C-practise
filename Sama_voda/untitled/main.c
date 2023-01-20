#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXS 10000
#define MINS (-10000)

typedef struct{
	char dir;
	int length;
}Step;

int random(int upper, int lower)
{
	return (rand() %(upper - lower + 1)) + lower;
}

int closest(int x1,int y1,int x2,int y2,int d1,int d2)
{
    float res1 = sqrt((float)pow(x1-d1,2)+pow(y1-d2,2));
    float res2 = sqrt((float)pow(x2-d1,2)+pow(y2-d2,2));
    res1*=1000;
    res2*=1000;
    res1=(int)res1;
    res2=(int)res2;
    if(res1>res2)//res 2 is closer
        return 2;
    if(res1<res2)
        return 1;//res 1 is closer
    if(res1==res2)
        return 0;//same spot
}

int distance(int x1,int y1,int x2,int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main()
{
	srand(time(NULL));
	int x = 0, y = 0;
	int dx =random(MAXS,MINS);//destination x
    int dy= random(MAXS,MINS);//destination y
    printf("dx - %d\ndy - %d\n\n\n",dx,dy);
    int res;
	Step step;
    int px=0,py=0;//previous
	while ((res = scanf(" %c %d ",&step.dir,&step.length))!=EOF)
	{
        printf("\nCurrently you are in a position (%d,%d)\nDestination:%d,%d\n",x,y,dx,dy);
        if(res!=2)
        {
            printf("Nesparavny vstup.\n");
            return 1;
        }
        printf("\nMaking %d steps in ",step.length);
        step.dir=tolower(step.dir);
        switch(step.dir)
        {
            case 'l':{x-=step.length;printf("left");break;}
            case 'r':{x+=step.length;printf("right");break;}
            case 'd':{y-=step.length;printf("bottom");break;}
            case 'u':{y+=step.length;printf("top");break;}
            default:return 3;
        }
        if(x<MINS || x>MAXS || y>MAXS || y<MINS)
        {
            printf("\nStep was out of the [MIN,MAX] range.\n");
            return 2;
        }
        printf(" direction\n");

        printf("\n------------------\n");
        printf("Now your cordinates are x=%d and y=%d",x,y);
        printf("\n------------------\n");
        if(distance(x,y,dx,dy)<=50) {
            printf("\nHori!\n");
            return 100;
        }

        if(closest(x,y,px,py,dx,dy)==2)
            printf("\nSama voda\n");
        if(closest(x,y,px,py,dx,dy)==1)
            printf("\nPrihoriva\n");
        px=x;
        py=y;
	}
}