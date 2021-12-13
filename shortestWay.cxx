#include <iostream>
#include <queue>
#include <vector>
#define inf 2000000001
using namespace std;
struct Edge
{
	int begin,end,weight;
};
struct Point
{
	int name,distance;
	bool operator<(const Point &another) const
	{
		return distance>another.distance;
	}
};
vector<Edge> graph[100001];
bool isVisited[100001];
int shortestDistance[100001];
void Dijkstra(int begin,int n,int m)
{
	for(int i=0;i<100001;i++)
	{
		isVisited[i]=false;
		shortestDistance[i]=inf;
	}
	priority_queue<Point> priorityQueue;
	Point head;
	head.name=begin;
	head.distance=0;
	shortestDistance[begin]=0;
	priorityQueue.push(head);
	while(!priorityQueue.empty())
	{
		Point p=priorityQueue.top();
		//printf("top's name is %d,distance is %d\n",p.name,p.distance);
		priorityQueue.pop();
		int u=p.name;
		if(isVisited[u]==true)
		{
			continue;
		}
		isVisited[u]=true;
		for(unsigned int i=0;i<graph[u].size();i++)
		{
			int v=graph[u][i].end;
			//printf("%d->%d,weight=%d\n",u,v,graph[u][i].weight);
			//printf("u's distance is %d, v's is %d\n",shortestDistance[u],shortestDistance[v]);
			if(shortestDistance[u]+graph[u][i].weight<shortestDistance[v])
			{
				shortestDistance[v]=shortestDistance[u]+graph[u][i].weight;
				//printf("%d's distance is %d\n",v,shortestDistance[v]);
				if(isVisited[v]==false)
				{
					p.name=v;
					p.distance=shortestDistance[v];
					priorityQueue.push(p);
				}
			}
		}
	}
}
int main()
{
	int n,m,begin,end;
	scanf("%d %d %d %d",&n,&m,&begin,&end);
	for(int i=0;i<m;i++)
	{
		int a,b,x;
		scanf("%d %d %d",&a,&b,&x);
		Edge newEdge1,newEdge2;
		newEdge1.begin=a;
		newEdge1.end=b;
		newEdge1.weight=x;
		graph[a].emplace_back(newEdge1);
		newEdge2.begin=b;
		newEdge2.end=a;
		newEdge2.weight=x;
		graph[b].emplace_back(newEdge2);
	}
	Dijkstra(begin,n,m);
	printf("%d",shortestDistance[end]);
}
/*
4 4 1 4
1 2 3
1 3 2
2 4 4
3 4 7
*/