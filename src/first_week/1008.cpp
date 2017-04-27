#include<stdio.h>
int main()
{
    int start,end,time,i,n;
    while(~scanf("%d",&n)&&n)
    {
        start=0;
        time=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&end);
            if(start>end)
                time=(start-end)*4+5;
            if(start<end)
                time=(end-start)*6+5;
        }
        printf("%d\n",time);
    }
    return 0;
}
