#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAX = 10404;
struct Edge
{
	int weight = 0;
	int next;
	int to;
};
int n, m;
int num = 0;
Edge edges[MAX];
int depth[MAX], from[MAX];
inline int getPos(int i, int j)
{
	return (i - 1) * m + j;
}
inline void insert(int u, int v, int w)
{
	edges[num].next = from[u];
	edges[num].to = v;
	edges[num].weight = w;
	from[u] = num;
	num++;
	edges[num].next = from[v];
	edges[num].to = u;
	edges[num].weight = w;
	from[v] = num;
	num++;
}
bool BFS(int start, int end)
{
	queue<int> q;
	memset(depth, 0, sizeof(depth));
	q.push(start);
	depth[start] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = from[temp]; i != -1; i = edges[i].next)
		{
			int to = edges[i].to;
			int weight = edges[i].weight;
			if (depth[to])
			{
				continue;
			}
			if (weight == 0)
			{
				continue;
			}
			depth[to] = depth[temp] + 1;
			q.push(to);
			if (to == end)
			{
				return true;
			}
		}
	}
	return false;
}
int DFS(int start, int end, int flow)
{
	if (start == end)
	{
		return flow;
	}
	int rest = flow;
	int i;
	for (i = from[start]; i != -1 && rest; i = edges[i].next)
	{
		int to = edges[i].to;
		int weight = edges[i].weight;
		if (weight && (depth[to] == depth[start] + 1))
		{
			int k = DFS(to, end, min(rest, weight));
			if (!k)
			{
				depth[to] = 0;
			}
			edges[i].weight -= k;
			edges[i ^ 1].weight += k;
			rest -= k;
		}
	}
	return flow - rest;
}
int main(int argc, char *argv[])
{
	scanf("%d %d", &n, &m);
	memset(from, -1, sizeof(from));
	int start = MAX - 1;
	int end = MAX - 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int name;
			scanf("%d", &name);
			if (i != n)
			{
				insert(getPos(i, j), getPos(i + 1, j), 1);
			}
			if (j != m)
			{
				insert(getPos(i, j), getPos(i, j + 1), 1);
			}
			if (name == 2)
			{
				insert(getPos(i, j), end, inf);
			}
			if (name == 1)
			{
				insert(start, getPos(i, j), inf);
			}
		}
	}
	int sum = 0;
	while (BFS(start, end))
	{
		while (int x=DFS(start, end, inf))
		{
			sum += x;
		}
	}
	printf("%d", sum);
}