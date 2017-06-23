#include<stdio.h>
#include<stdlib.h>
#define MAXV 100
#define INF 9999
typedef struct
{
	int data;
	int parent;
}QUERE;

typedef struct
{
	int no;
}vertextype;

typedef struct
{
	int edges[MAXV][MAXV];
	int n,e;
	vertextype vexs[MAXV];
}MGraph;


void CreateMGraph(MGraph &G)
{
	int i,j;
	int A[MAXV][MAXV]={{0,400,600,600,INF,INF,INF},{INF,0,100,INF,700,INF,INF},{INF,INF,0,INF,600,400,INF},{INF,INF,200,0,INF,500,INF},{INF,INF,INF,INF,0,INF,600},{INF,INF,INF,INF,100,0,800},{INF,INF,300,INF,INF,INF,0}};
		G.n =7,G.e =12;
	for(i=0;i<G.n ;i++)
		for(j=0;j<G.n;j++)
		G.edges[i][j]=A[i][j];
}

void dispath(MGraph G,int dist[],int path[],int S[],int v)
{
	int i,j,k;
	int apath[MAXV],d;
	for(i=0;i<G.n;i++)
		if(S[i]==1&&i!=v)
		{
			printf("  从顶点%d到顶点%d的路径长度为：%d\t路径为：",v,i,dist[i]);
			d=0;apath[d]=i;
			k=path[i];
			if(k==-1)
				printf("无路径\n");
			else
			{
				while(k!=v)
				{
					d++;
					apath[d]=k;
					k=path[k];
				}
				d++;
				apath[d]=v;
				printf("%d",apath[d]);
				for(j=d-1;j>=0;j--)
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}

void Dijkstra(MGraph G,int v)
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];
	int mindis,i,j,u;
	for(i=0;i<G.n;i++)
	{
		dist[i]=G.edges[v][i];
		s[i]=0;
		if(G.edges[v][i]<INF)
			path[i]=v;
		else
			path[i]=-1;
	}
	s[v]=1;
	path[v]=0;
	for(i=0;i<G.n;i++)
	{
		mindis=INF;
		for(j=0;j<G.n;j++)
			if(s[j]==0&&dist[j]<mindis)
			{
				u=j;
				mindis=dist[i];
			}
			s[u]=1;
			for(j=0;j<G.n;j++)
				if(s[j]==0)
					if(G.edges[u][j]<INF&&dist[u]+G.edges[u][j]<dist[j])
					{
						dist[j]=dist[u]+G.edges[u][j];
						path[j]=u;
					}
	}
	dispath(G,dist,path,s,v);
}

void Dispath(MGraph G,int A[][MAXV],int path[][MAXV])
{
	int i,j,k,s;
	int apath[MAXV],d;
	for(i=0;i<G.n;i++)
		for(j=0;j<G.n;j++)
		{
			if(A[i][j]!=INF&&i!=j)
			{
			printf("  从%d到%d的路径为：",i,j);
			k=path[i][j];
			d=0;apath[d]=j;
			while(k!=-1&&k!=j)
			{
				d++;
				apath[d]=k;
				k=path[i][k];
			}
				d++;
				apath[d]=i;
			//	printf("%d",apath[d]);
				for(s=d-1;s>=0;s--)
					printf("-%d",apath[s]);
				printf("\t路径长度为：%d\n",A[i][j]);
			}
		}
}


void Floyd(MGraph G)
{
	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for(i=0;i<G.n;i++)
		for(j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			if(i!=j&&G.edges[i][j]<INF)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
		for(k=0;k<G.n;k++)
		{
			for(i=0;i<G.n;i++)
				for(j=0;j<G.n;j++)
					if(A[i][j]>A[i][k]+A[k][j])
					{
						A[i][j]=A[i][k]+A[k][j];
						path[i][j]=k;
					}
		}
		Dispath(G,A,path);
}



void shortpath(MGraph G,int w,int u)
{
	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,x;
	for(i=0;i<G.n;i++)
		for(j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			if(i!=j&&G.edges[i][j]<INF)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
		for(x=0;x<G.n;x++)
		{
			for(i=0;i<G.n;i++)
				for(j=0;j<G.n;j++)
					if(A[i][j]>A[i][x]+A[x][j])
					{
						A[i][j]=A[i][x]+A[x][j];
						path[i][j]=x;
					}
		}
		int k,s;
		int apath[MAXV],d;
		if(A[w][u]!=INF&&w!=u)
			{
				printf("  从%d到%d的路径为：",w,u);
				k=path[w][u];
				d=0;apath[d]=u;
				while(k!=-1&&k!=u)
				{
					d++;
					apath[d]=k;
					k=path[w][k];
				}
					d++;
					apath[d]=w;
				//	printf("%d",apath[d]);
					for(s=d-1;s>=0;s--)
						printf("-%d",apath[s]);
					printf("\t路径长度为：%d\n",A[w][u]);
			}
}



int main()
{
	int v,w,k,flag=1;
	MGraph G;

	CreateMGraph(G);
	//int A[MAXV][MAXV]={{0,400,600,600,INF,INF,INF},{INF,0,100,700,INF,INF},{INF,INF,0,INF,600,400,INF},{INF,INF,200,0,INF,500,INF},{INF,INF,INF,INF,0,INF,600},{INF,INF,INF,INF,100,0,800},{INF,INF,300,INF,INF,INF,0}};
	//char B[5]={a,b,c,d,e};
	//for(i=0;i<5;i++)
		//G->vexs[i]=B[i];
	//for(i=0;i<5;i++)
	//	for(j=0;j<5;j++)
	//	G.edges[i][j]=A[i][j];
	//G.n =5,G.e =5;
	while(flag!=0)
	{
		printf("**********求城市之间的最短路径***********\n");
		printf("                                         \n");
		printf("请用户选择您所需要的功能：\n");
		printf("1.求一个城市到所有城市的最短距离\n");
		printf("2.求任意两个城市之间的最短距离\n");
		printf("3.求固定两个城市之间的路径\n");
		printf("4.   退出\n");
		scanf("%d",&flag);
		if(flag==2)
			Floyd(G);
		else if(flag==3)
		{
			printf("输入起点终点：v,w:\n");
			scanf("%d %d",&v,&w);
			k=G.edges[v][w];
			if(k==0)
				printf("顶点%d到顶点%d无路经\n",v,w);
			else
				shortpath(G,v,w);
		}
		else if(flag==1)
			{
				printf("求单源路径，输入源点v:");
				scanf("%d",&v);
				Dijkstra(G,v);
			}
		else if(flag==4)
		{
			printf("选择结束\n");
			flag=0;
		}
	}
	return 0;
}
