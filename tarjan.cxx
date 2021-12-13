#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Edge
{
	int begin;
	int end;
	int weight;
};
vector<int> scc;
stack<int> points;
//stack<Edge> stackEdges;
Edge edges[5001];
int DFN[3001] = {0};
int Low[3001] = {0};
bool out[3001] = {false};
bool isExist = false;
void check(int length, int m)
{
	if (length == 1)
	{
		return;
	}
	int sum = 0;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((edges[j].end == scc[i]) && (edges[j].begin == scc[i + 1]))
			{
				sum += edges[j].weight;
				//printf("%d->%d,weight=%d,sum=%d\n", edges[j].begin, edges[j].end, edges[j].weight, sum);
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		if ((edges[j].begin == scc[0]) && (edges[j].end == scc[length - 1]))
		{
			sum += edges[j].weight;
			//printf("%d->%d,weight=%d,sum=%d\n", edges[j].begin, edges[j].end, edges[j].weight, sum);
		}
	}
	if (sum < 0)
	{
		isExist = true;
	}
}
void tarjan(int vertexNumber, int edgesNumber, int begin, int number)
{
	if (isExist)
	{
		return;
	}
	points.push(begin);
	DFN[begin] = number;
	Low[begin] = number;
	//printf("DFN[%d]is %d\n",begin,number);
	//printf("Low[%d]is %d\n",begin,number);
	for (int i = 0; i < edgesNumber; i++)
	{
		if (isExist)
		{
			break;
		}
		if (edges[i].begin != begin)
		{
			continue;
		}
		else
		{
			if (DFN[edges[i].end] == 0)
			{
				//printf("%d->%d\n",edges[i].begin,edges[i].end);
				tarjan(vertexNumber, edgesNumber, edges[i].end, number + 1);
				Low[begin] = min(Low[begin], Low[edges[i].end]);
			}
			else if (out[begin] == false)
			{
				Low[begin] = Low[edges[i].end];
			}
		}
	}
	if (DFN[begin] == Low[begin])
	{
		int count = 0;
		while (points.top() != begin)
		{
			//printf("%d ", points.top());
			scc.emplace_back(points.top());
			count++;
			points.pop();
		}
		//printf("%d\n", points.top());
		scc.emplace_back(points.top());
		count++;
		points.pop();
		check(count, edgesNumber);
		scc.clear();
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		edges[i].begin = a;
		edges[i].end = b;
		edges[i].weight = x;
	}
	tarjan(n, m, edges[0].begin, 1);
	if (isExist)
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