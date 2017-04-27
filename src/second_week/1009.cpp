#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int J,F;
    double jun;
}shu[10000];

bool cmp(node a,node b){
    return a.jun>b.jun;
}

int main()
{
    int M,N;
    while(scanf("%d %d",&M,&N)!=EOF)
    {
        if(M==-1&&N==-1)
        break;
        for(int i=0;i<N;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            double d=(double)a/b;
            shu[i].J=a;
            shu[i].F=b;
            shu[i].jun=d;
        }
        sort(shu,shu+N,cmp);
        int sum=0;
        double ans=0.0;
        for(int i=0;i<N;i++)
        {
            if(sum+shu[i].F<=M)
                {
                    ans+=shu[i].J;
                    sum+=shu[i].F;
                }
                else
                {
                    ans+=(double(M-sum)/shu[i].F)*shu[i].J;
                    break;
                }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}


