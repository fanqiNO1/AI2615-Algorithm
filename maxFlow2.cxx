#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int m,n;
const int INF=0x3f3f3f3f;
struct Edge
{
	int to=-1;
	int weight=-1;
	int next=-1;
};
const int MAX=200002;
int Count=0;
int from[MAX];
Edge edges[MAX]={};
int depth[MAX];
inline void insert(int u,int v,int w)
{
	edges[Count].to=v;
	edges[Count].weight=w;
	edges[Count].next=from[u];
	from[u]=Count;
	Count++;
	edges[Count].to=u;
	edges[Count].weight=0;
	edges[Count].next=from[v];
	from[v]=Count;
	Count++;
	//printf("%d->%d,weight=%d,%d\n",u,v,w,Count);
}
struct Pig
{
	int num=0;
	int custom=-1;
};
int Source=0;
int Target=MAX-1;
Pig pigs[1011];
bool BFS(int source,int target)
{
	memset(depth,0,sizeof(depth));
	queue<int> q;
	q.push(source);
	depth[source]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=from[u];i!=-1;i=edges[i].next)
		{
			int v=edges[i].to;
			int w=edges[i].weight;
			if((depth[v])||(!w))
			{
				continue;
			}
			depth[v]=depth[u]+1;
			q.push(v);
			{
				if(v==target)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int DFS(int source,int target,int flow)
{
	//printf("%d->%d,flow=%d\n",source,target,flow);
	if(source==target)
	{
		return flow;
	}
	int rest=flow,i;
	for(i=from[source];i!=-1 && rest;i=edges[i].next)
	{
		int v=edges[i].to;
		int w=edges[i].weight;
		if(w && depth[v]==depth[source]+1)
		{
			int temp=DFS(v,target,min(rest,w));
			if(!temp)
			{
				depth[v]=0;
			}
			edges[i].weight-=temp;
			edges[i^1].weight+=temp;
			rest-=temp;
		}
	}
	return flow-rest;
}
int main(int argc, char *argv[])
{
	memset(from,-1,sizeof(from));
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&pigs[i].num);
	}
	for(int i=1;i<=n;i++)
	{
		int keyNum;
		scanf("%d",&keyNum);
		int num=0;
		for(int j=0;j<keyNum;j++)
		{
			int key;
			scanf("%d",&key);
			if(pigs[key].custom==-1)
			{
				num+=pigs[key].num;
			}
			else
			{
				insert(pigs[key].custom,i,INF);
			}
			pigs[key].custom=i;
		}
		int items;
		scanf("%d",&items);
		insert(Source,i,num);
		insert(i,Target,items);
	}
	int sum=0;
	while(BFS(Source,Target))
	{
		while(int x=DFS(Source,Target,INF))
		{
			//printf("%d ",x);
			sum+=x;
		}
	}
	printf("%d",sum);
}
/*
3 3
3 1 10
2 1 2 2
2 1 3 3
1 2 6
*/