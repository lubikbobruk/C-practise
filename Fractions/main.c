#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}Fraction;

void printRes(Fraction * res,int endPrint)
{
   int temp = res->y;
   printf(":");
   if(res->y < 0)
   {
       temp *=-1;
       printf("-");
   }
   if(res->y == 1 && endPrint)
     printf("%d\n",res->x);
   else
        printf("%d/%d\n",res->x,temp);
}

void normalizeFraction(Fraction * frac)
{// 2/6  2/8 2/16 4/16  8/16   3/8 128/4 == 32
   if(frac->x == frac->y)
   {
       frac->x = frac->y = 1;
       return;
   }
   if(frac->x > frac->y && (frac->x % frac->y ==0 ))
   {
       frac->x /= frac->y;
       frac->y = 1;
       return;
   }
   if(frac->y > frac->x && (frac->y % frac->x == 0))
   {
        frac->y/=frac->x;
        frac->x=1;
        return;
   }
}

void shorten(Fraction * frac)
{
    for(int i=2;i<=frac->x && i<=frac->y;i++)
    {
        if(frac->x % i==0 && frac->y%i==0)
        {
            frac->x /= i;
            frac->y /= i;
        }
    }
}

double precision(double x){x*=1000;x/=1000;return x;}

void calc(Fraction * first,Fraction * second,char oper,Fraction * result,int power)
{
    switch(oper)
    {
        case '+':
        {
            result->x=first->x+second->x;
            result->y=first->y;
            break;
        }
        case '-':
        {
            result->x=first->x-second->x;
            result->y=first->y;
            break;
        }
        case '*':
        {
            result->x=first->x*second->x;
            result->y=first->y*second->y;
            break;
        }
        case '/':
        {
            result->x=first->x*second->y;
            result->y=first->y*second->x;
            break;
        }
        case '^':
        {
            if(power==4)
            {
                result->x = pow(first->x, second->x);
                result->y = pow(first->y, second->x);
            }
            if(power==5)
            {
                result->x = pow(first->x, precision((double)second->x/(double)second->y));
                result->y = pow(first->y, precision((double)second->x/(double)second->y));
            }
            break;
        }
    }
    int lMinus=0,rMinus=0;
    if(result->x < 0){lMinus++;result->x *= -1;}
    if(result->y < 0) {rMinus++;result->y *= -1;}
    normalizeFraction(result);
    shorten(result);
    if(lMinus)
        result->x*=-1;
    if(rMinus)
        result->y*=-1;
    printRes(result,1);
}

void commonDenom(Fraction * num1,Fraction * num2)
{
    int divisor=1;
    if(num1->y == 1)
    {
        num1->y = num2->y;
        num1->x *= num2->y;
        return;
    }
    if(num2->y == 1)
    {
        num2->y = num1->y;
        num2->x *= num1->y;
        return;
    }
    int max = num1->y >= num2->y ? num1->y : num2->y;
    for(int i = 2;i<=max;i++)
    {
        if(i%num1->y==0 && i%num2->y==0)
        {
            divisor = i;
            break;
        }
    }
    num1->x*=divisor/num1->y;
    num1->y=divisor;
    num2->x*=divisor/num2->y;
    num2->y=divisor;
}

int main()
{
    Fraction first,second,result;
    char op;
    int power;
    while(1)
    {
        printf("$");
        if ((power = scanf(" %c %d/%d %d/%d", &op, &first.x, &first.y, &second.x, &second.y)) < 4)
        {
            puts("Invalid input.");
            return 1;
        }
        if(power == 4 && op!='^')
        {
            puts("Invalid input.");
            return 4;
        }
        puts("Checkpoint1");
        if(op!='*' && op!='+'&& op!='-'&& op!='/' && op!='^')
        {
            puts("Invalid operator.");
            return 2;
        }
        puts("Checkpoint2");
        if(first.y == 0 || second.y==0)
        {
            puts("Can`t divide ny zero.");
            return 3;
        }
        puts("Checkpoint3");
        if(power==5)
            normalizeFraction(&second);
        normalizeFraction(&first);
        printf("Normalizing:\n");
        printRes(&first, 0);
        if(power==5)
            printRes(&second, 0);
        if(op == '+' || op == '-')
        {
            commonDenom(&first, &second);
            printf("Common Dev:\n");
            printRes(&first, 0);
            printRes(&second, 0);
        }
        calc(&first,&second,op,&result,power);
    }
}