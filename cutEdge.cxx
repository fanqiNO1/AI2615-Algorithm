#include <iostream>
#include <algorithm>
using namespace std;
int dp[200][200] = {};
struct Point
{
	int name = 0;
	int weight = 0;
	int degree = 0;
	int left = 0;
	int right = 0;
};
Point tree[200];
bool cmp(Point a, Point b)
{
	if (a.degree > b.degree)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int treeSize, edgesLeft;
	scanf("%d %d", &treeSize, &edgesLeft);
	tree[1].degree = 1;
	tree[1].name = 1;
	for (int i = 2; i <= treeSize; i++)
	{
		tree[i].name = i;
		scanf("%d", &tree[i].weight);
		dp[i][0] = tree[i].weight;
	}
	for (int i = 1; i < treeSize; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (tree[y].degree != 0)
		{
			swap(x, y);
		}
		if (tree[x].degree != 0)
		{
			tree[y].degree = tree[x].degree + 1;
			if (tree[x].left == 0)
			{
				tree[x].left = y;
			}
			else
			{
				tree[x].right = y;
			}
		}
	}
	sort(tree, tree + treeSize + 1, cmp);
	/*for(int i=0;i<=treeSize;i++)
	{
		printf("Point[%d].weight=%d,degree=%d,left=%d,right=%d\n",tree[i].name,tree[i].weight,tree[i].degree,tree[i].left,tree[i].right);
	}*/
	for (int i = 1; i <= treeSize; i++)
	{
		dp[tree[i].name][1] = tree[i].weight + max(dp[tree[i].left][0], dp[tree[i].right][0]);
		for (int j = 2; j <= edgesLeft; j++)
		{
			int maxWeight = max(dp[tree[i].left][j - 1], dp[tree[i].right][j - 1]);
			for (int k = 0; k <= j - 2; k++)
			{
				if (dp[tree[i].left][j - 2 - k] + dp[tree[i].right][k] > maxWeight)
				{
					maxWeight = dp[tree[i].left][j - 2 - k] + dp[tree[i].right][k];
				}
			}
			dp[tree[i].name][j] = tree[i].weight + maxWeight;
		}
	}
	printf("%d", dp[1][edgesLeft]);
}
/*
5 2
20 1 10 20
1 3
1 4
2 3
3 5

*/