#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 2000001;
vector<int> adj[MAX];
vector<int> adjInv[MAX];
bool visited[MAX];
bool visitedInv[MAX];
stack<int> s;
int scc[MAX];
int counter = 1;
int a[MAX];
int b[MAX];
void addEdges(int a, int b)
{
	adj[a].emplace_back(b);
}
void addEdgesInverse(int a, int b)
{
	adjInv[b].emplace_back(a);
}
void dfsFirst(int u)
{
	if (visited[u])
		return;
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
		dfsFirst(adj[u][i]);
	s.push(u);
}
void dfsSecond(int u)
{
	if (visitedInv[u])
		return;
	visitedInv[u] = 1;
	for (int i = 0; i < adjInv[u].size(); i++)
		dfsSecond(adjInv[u][i]);
	scc[u] = counter;
}
void is2Sat(int n, int m, int *a, int *b)
{
	for (int i = 0; i < m; i++)
	{
		if (a[i] > 0 && b[i] > 0)
		{
			addEdges(a[i] + n, b[i]);
			addEdgesInverse(a[i] + n, b[i]);
			addEdges(b[i] + n, a[i]);
			addEdgesInverse(b[i] + n, a[i]);
		}

		else if (a[i] > 0 && b[i] < 0)
		{
			addEdges(a[i] + n, n - b[i]);
			addEdgesInverse(a[i] + n, n - b[i]);
			addEdges(-b[i], a[i]);
			addEdgesInverse(-b[i], a[i]);
		}

		else if (a[i] < 0 && b[i] > 0)
		{
			addEdges(-a[i], b[i]);
			addEdgesInverse(-a[i], b[i]);
			addEdges(b[i] + n, n - a[i]);
			addEdgesInverse(b[i] + n, n - a[i]);
		}

		else
		{
			addEdges(-a[i], n - b[i]);
			addEdgesInverse(-a[i], n - b[i]);
			addEdges(-b[i], n - a[i]);
			addEdgesInverse(-b[i], n - a[i]);
		}
	}

	for (int i = 1; i <= 2 * n; i++)
		if (!visited[i])
			dfsFirst(i);

	while (!s.empty())
	{
		int n = s.top();
		s.pop();

		if (!visitedInv[n])
		{
			dfsSecond(n);
			counter++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (scc[i] == scc[i + n])
		{
			printf("No");
			return;
		}
	}
	printf("Yes");
	return;
}

int main()
{
	// n is the number of variables
	// 2n is the total number of nodes
	// m is the number of clauses
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int n1, v1, n2, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d %d", &n1, &v1, &n2, &v2);
		if (v1 == 0)
		{
			a[i] = -n1;
		}
		else
		{
			a[i] = n1;
		}
		if (v2 == 0)
		{
			b[i] = -n2;
		}
		else
		{
			b[i] = n2;
		}
	}
	is2Sat(n, m, a, b);
	return 0;
}