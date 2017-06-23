#include <iostream>  
#include <cstdio>  
#include <cstring>  
#define inf 99999999;  
using namespace std;  
int dp[1100][110];  
int c[110];  
int v[110];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(;t--;)  
    {  
        int n,m,l;  
        scanf("%d%d%d",&n,&m,&l);  
        int i;  
        for(i=1;i<=n;i++)  
            scanf("%d%d",&c[i],&v[i]);  
        int j,k;  
        memset(dp,-1,sizeof(dp));  
        for(j=0;j<=l;j++)  
            dp[j][0]=0;  
        for(i=1;i<=n;i++)  
        {  
            for(j=l;j>=c[i];j--)        
            {  
                for(k=m;k>=1;k--)       
                {  
                    if(dp[j-c[i]][k-1]!=-1)  
                        dp[j][k]=max(dp[j][k],dp[j-c[i]][k-1]+v[i]);  
                }  
            }  
        }  
        if(dp[l][m]==-1)  
            printf("0\n");  
        else  
            printf("%d\n",dp[l][m]);  
    }  
    return 0;  
}  
