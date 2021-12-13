#include <iostream>
#include <algorithm>
using namespace std;
struct Edge
{
	int begin;
	int end;
	int weight;
};
bool cmp(Edge a,Edge b)
{
	if(a.weight<b.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}
unsigned long long sum=0;
struct treePoint
{
	int name;
	int rank;
	treePoint* parent;
};
void makeSet(treePoint* tree,int n)
{
	for(int i=0;i<n;i++)
	{
		tree[i].name=i;
		tree[i].rank=0;
		tree[i].parent=NULL;
	}
}
int findRoot(treePoint *point)
{
	if(point->parent!=NULL)
	{
		return findRoot(point->parent);
	}
	else
	{
		return point->name;
	}
}
void unionSet(treePoint a,treePoint b,treePoint* tree)
{
	int aRoot=findRoot(&a);
	int bRoot=findRoot(&b);
	//printf("%d's root is %d\n",a.name,aRoot);
	//printf("%d's root is %d\n",b.name,bRoot);
	if(aRoot==bRoot)
	{
		return;
	}
	if(tree[aRoot].rank>tree[bRoot].rank)
	{
		tree[bRoot].parent=&tree[aRoot];
	}
	else
	{
		tree[aRoot].parent=&tree[bRoot];
		if(tree[aRoot].rank==tree[bRoot].rank)
		{
			tree[bRoot].rank++;
		}
	}
}
void minSpanningTree(int n,int m,Edge* edges,treePoint* tree)
{
	makeSet(tree,n+1);
	for(int i=0;i<m;i++)
	{
		if(findRoot(&tree[edges[i].begin])==findRoot(&tree[edges[i].end]))
		{
			continue;
		}
		else
		{
			sum+=edges[i].weight;
			unionSet(tree[edges[i].begin],tree[edges[i].end],tree);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	Edge* edges=new Edge[m];
	treePoint* tree=new treePoint[n+1];
	for(int i=0;i<m;i++)
	{
		int a,b,x;
		scanf("%d %d %d",&a,&b,&x);
		edges[i].begin=a;
		edges[i].end=b;
		edges[i].weight=x;
	}
	sort(edges,edges+m,cmp);
	minSpanningTree(n,m,edges,tree);
	/*
	for(int i=0;i<m;i++)
	{
		printf("%d->%d,%d\n",edges[i].begin,edges[i].end,edges[i].weight);
	}
	*/
	printf("%llu",sum);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 1
1 5 3
2 3 6
2 5 5
3 4 5
3 5 4
4 5 3
*/
/*
4 4
2 1 4
2 3 2
3 4 2
4 2 2 
*/