#include<stdio.h>
#include<string.h>
#include<queue>
#define MAX 20
using namespace std;
int visit[MAX+1]={0};
typedef struct
{
    char vexs[MAX];
    int A[MAX+1][MAX+1];
    int vexnum,arcnum;
}MGraph;
int Locatevex(char ch1,MGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==ch1)
            return i;
    }
}
void InitGraph(MGraph &G)
{
    int i,j,k;
    char ch1,ch2;
    printf("input the Graph:");
    scanf("%d %d%*c",&G.vexnum,&G.arcnum);
    printf("input the Locatevex:");
    for(i=0;i<G.arcnum;i++)
    {
        scanf("%c",&G.vexs[i]);
    }
    getchar();
    printf("input side:");
    for(i=0;i<G.arcnum;i++)
    {
        scanf("%c %c%*c",&ch1,&ch2);
        j=Locatevex(ch1,G);
        k=Locatevex(ch2,G);
        G.A[j][k]=1;
        G.A[k][j]=1;
    }
}

void DFS(int i,MGraph G)
{
    int j;
    visit[i]=1;
    printf("%c",G.vexs[i]);
    for(j=0;j<G.vexnum;j++)
    {
        if(!visit[j]&&G.A[i][j])
            DFS(j,G);
    }
}

void BFS(MGraph G)
{
    int i,j,k;
    char ch;
    queue<char> q;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visit[i])
        {
            printf("%c",G.vexs[i]);
            visit[i]=1;
            q.push(G.vexnum);
            while(!q.empty())
            {
                ch=q.front();
                q.pop();
                k=Locatevex(ch,G);
            }
            for(j=0;j<G.vexnum;j++)
            {
                if(!visit[j]&&G.A[k][j])
                {
                    visit[j]=1;
                    printf("%c",G.vexs[j]);
                    q.push(G.vexs[j]);
                }
            }
        }
    }
}

int main()
{
	int i;
	MGraph G;
	memset(G.A,0,sizeof(G.A));
	InitGraph(G);


	printf("图的深度优先搜索遍历:");
	for(i=0;i<G.vexnum;i++)
		if(!visit[i])
			DFS(i,G);

	memset(visit,0,sizeof(visit));
	putchar('\n');

	printf("图的广度优先搜索遍历:");

	BFS(G);

	return 0;


