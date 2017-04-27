#include<stdio.h>
int sum=1;
int i=1;
void divison(int x,int y)
{
    if(x/i==1&&y/i==1)
        printf("%d\n",sum);
    else
    {
        if(x%i==0&&y%i==0)
        {
            x=x/i;
            y=y/i;
           sum=divison(x/i,y/i)*sum;
        }
    }
    i++;
    return sum;
}
int main()
{
    int x,y;
    while(~scanf("%d %d",&x,&y))
    {
    divison(x,y);
    printf("%d",sum);
    return 0;
    }
}
