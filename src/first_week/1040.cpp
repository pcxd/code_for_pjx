#include<stdio.h>
int main()
{
    int T,N,i,j,num[1000],temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d ",&N);
        for(i=1;i<=N;i++)
            scanf("%d",&num[i]);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(num[i]>num[j])
                {
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
        for(i=N;i>=1;i--)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    return 0;
}
