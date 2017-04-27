#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1002];
char s[1002];
int main()
{
    int count;
    char *p;
    while(scanf("%s",s)==1)
    {
        count=0;
        p=strtok(s,"5");
        while(p!=NULL)
        {
            scanf(p,"%d",&a[count++]);
            p=strtok(NULL,"5");
        }
        sort(a,a+count);
        int flag=0;
        for(int i=0;i!=count;++i)
            if(!flag)
            {
                printf("%d",a[i]);
                flag=1;
            }
            else printf("%d",a[i]);
            putchar('\n');


    }
    return 0;
}
