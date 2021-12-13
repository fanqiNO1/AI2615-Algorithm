#include <iostream>
#include <vector>
using namespace std;
struct Person
{
	int name;
	vector<int> neighbors;
	bool isAsked = false;
	int match = -1;
};
Person people[222];
int n, num;
bool find(int x)
{
	for (int i = 0; i < people[x].neighbors.size(); i++)
	{
		int j = people[x].neighbors[i];
		if (people[j].isAsked)
		{
			continue;
		}
		people[j].isAsked = true;
		if ((people[j].match == -1) || (find(people[j].match)))
		{
			//printf("%d--%d\n", x, j);
			people[x].match = j;
			people[j].match = x;
			return true;
		}
	}
	return false;
}
void match()
{
	for (int i = 0; i < n; i++)
	{
		if (people[i].match == -1)
		{
			for (int j = 0; j < n; j++)
			{
				people[j].isAsked = false;
			}
			if (find(i))
			{
				num++;
			}
		}
	}
}
int main()
{
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		people[i].name = i;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		people[x].neighbors.emplace_back(y);
		people[y].neighbors.emplace_back(x);
	}
	match();
	printf("%d", n - num);
}
/*
8 6
0 2
2 3
3 5
1 4
1 6
3 1
*/