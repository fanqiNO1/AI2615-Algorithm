#include <iostream>
using namespace std;
struct Edge
{
	int begin;
	int end;
};
Edge edges[1000001];
int ancestors[100001];
int getRoot(int a)
{
	int t = a;
	while (ancestors[t] != -1)
		t = ancestors[t];
	return t;
}
int main()
{
	int n, m;
	int vertex1, vertex2;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ancestors[i] = -1;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &edges[i].begin, &edges[i].end);
	}
	for (int i = 1; i <= m; i++)
	{
		vertex1 = getRoot(edges[i].begin);
		vertex2 = getRoot(edges[i].end);
		if (vertex1 == vertex2)
		{
			printf("Yes");
			flag = true;
			break;
		}
		else
		{
			ancestors[vertex1] = vertex2;
		}
	}
	if (!flag)
	{
		printf("No");
	}
	return 0;
}