#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
const int N=10000;
int n,flag[N+N];
char O1[N],O2[N];
int main()
{
    int i,t1,t2,tf;
    while(scanf("%d",&n)!=EOF)
    {
        stack<char> s;
        memset(flag,0,sizeof(flag));
        memset(O1,0,sizeof(O1));
        memset(O2,0,sizeof(O2));
        getchar();  // can qudiao
        for(i=0;i<n;i++)
        {
            scanf("%c",&O1[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%c",&O2[i]);
        }
        int ok=1;t1=0;t2=0;tf=0;
        while(t2<n)
        {
            if(O1[t1]==O2[t2])
            {
                t1++;
                t2++;
                flag[tf++]=1;
                flag[tf++]=0;
            }
            else if (!s.empty()&&s.top()==O2[t2])
            {
                s.pop();
                t2++;
                flag[tf++]=1;
            }
            else if(t1<n)
            {
                s.push(O1[t1++]);
                flag[tf++]=1;
            }
            else
            {
                ok=0;
                break;
            }
        }
        if(ok==1)
        {
            printf("Yes.\n");
            for(i=0;i<tf;i++)
            {
                if(tf==1)
                    printf("in\n");
                else
                    printf("out\n");
            }
            printf("FINISH\n");
        }
        else
        {
            printf("NO.\n");
            printf("FINISH\n");
        }
    }
    return 0;
}
