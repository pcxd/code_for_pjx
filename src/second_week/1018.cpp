#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t,i,n;
    double w;
    scanf("%d",&t);
    while(t--)
    {
            scanf("%d",&n);
            w=1;
            for(i=1;i<=n; i++)
            w=w+log10((double)i);
        printf("%d\n",(int) w);
    }
    return 0;
}
