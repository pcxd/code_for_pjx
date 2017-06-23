#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int t,w,h,l,m,maxvalue,allvalue;
char maze[55][55];
bool a[55][55];
int value[3];
int len[13][13];
bool fb[15];
int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct p
{
    int x,y,r;
    p(int a,int b,int c)
    {
        x=a;y=b;r=c;
    }
};
struct
{
    int x,y;
}bf[15];
void bfs(int x,int y,int record)
{
    queue<p> Q;
    p f(x,y,0);
    Q.push(f);
    while(!Q.empty())
    {
        p temp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = temp.x + go[i][0];
            int ny = temp.y + go[i][1];
            int nr = temp.r + 1;
            if(nx<0||ny<0||nx>=h||ny>=w||a[nx][ny]||maze[nx][ny]=='*')
            {
                continue;
            }
            if(maze[nx][ny]>='A'&&maze[nx][ny]<='J')
            {
                len[record][maze[nx][ny]-'A'+1] = nr ;
            }
            if(maze[nx][ny]=='<')
                len[record][11]=nr;
            a[nx][ny] = 1 ;
            p.next (nx,ny,nr);
            Q.push (next);

        }
    }
    return ;
}
void dfs(int tempvalue,int pre,int time)
{
    if(time>1||allvalue==maxvalue)
    if(pre==11)
    {
        if(tempvalue>maxvalue)
            maxvalue = tempvalue ;
        return ;
    }
    for(int i=1;i<=11;i++)
    {
        if(i>m&&i<11)
        {
            i = 10 ;
            continue;
        }
        if(fb[i]==0)
        {
            fb[i]=1;
            dfs(tempvalue + value[i],i,time + len[pre][i]);
            fb[i]=0;
        }
    }
    return;
}
 int main()
 {
     cin>>t;
     int u=0;
     while(t--)
     {

         maxvalue = -1 ;
         allvalue = 0 ;
         memset(fb,0,sizeof(fb));
         memset(len,0,sizeof(len));
         cin>>w>>h>>m;
         for(int i=1;i<=m;i++)
         {
             cin>>value[i];
             allvalue += value[i];
         }
         for(int i=0;i<h;i++)
         {
             for(int j=0;j<w;j++)
            {
             cin>>maze[i][j];
             if(maze[i][j]=='@')
             {
                 bf[0].x = i ;
                 bf[0].y = j ;
             }
             if(maze[i][j]>='A'&&maze[i][j]<='J')
             {
                 bf[maze[i][j]-'A'+1].x = i ;
                  bf[maze[i][j]-'A'+1].y = j ;
             }
             if(maze[i][j]=='<')
             {
                 bf[11].x = i ;
                 bf[11].y = j ;
             }
         }
         }

     }
     for(int i=0;i<=m;i++)
     {
         memset(a,0,sizeof(a));
         a[bf[i].x][bf[i].y] = 1 ;
         bfs(bf[i].x,bf[i].y,i);
     }
     memset(fb,0,sizeof(fb));
     dfs(0,0,0);
     printf("Case %d;\n",++u);
     if(maxvalue<0||len[0][11]==0)
        printf("Impossible\n");
     else printf("The best score is %d\n",maxvalue);
     if(t) printf("\n");
 }

























