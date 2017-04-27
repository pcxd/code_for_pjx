#include<stdio.h>

int main()
{
	int i;
	int N;
	int n,m;
	int a,b;
	int count,x;

	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		x=1;
		while(scanf("%d %d",&n,&m),n>0)
		{
			count=0;
			for(a=1;a<n-1;a++)
				for(b=a+1;b<n;b++)
					if((a*a+b*b+m)%(a*b)==0)
						count++;
			printf("Case %d: %d\n",x++,count);
		}
		if(i!=N-1)
			printf("\n");
	}
	return 0;
}

