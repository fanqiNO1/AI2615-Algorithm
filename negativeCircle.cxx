#include <iostream>
#define inf 5e7+1
using namespace std;
struct Edge
{
	int begin;
	int end;
	int weight;
};
bool isExist=false;
void negativeCircle(int* distance,Edge* edges,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(distance[edges[j].begin]+edges[j].weight<distance[edges[j].end])
			{
				distance[edges[j].end]=distance[edges[j].begin]+edges[j].weight;
				if(i==n-1)
				{
					isExist=true;
				}
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int* distance=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		distance[i]=inf;
	}
	Edge* edges=new Edge[m];
	for(int i=0;i<m;i++)
	{
		int a,b,x;
		scanf("%d %d %d",&a,&b,&x);
		edges[i].begin=a;
		edges[i].end=b;
		edges[i].weight=x;
	}
	distance[edges[0].begin]=0;
	negativeCircle(distance,edges,n,m);
	if(isExist)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}
/*
4 4
2 1 4
2 3 2
3 4 2
4 2 -8
*/
/*
3 2
1 2 1
2 1 -1
*/