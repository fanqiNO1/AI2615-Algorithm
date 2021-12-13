#include <iostream>

using namespace std;
const int MOD = 1e9 + 7;
int dp[222][65][65];
int broken[222]={0};
//dp[i][j][k]: i is the row we choose now, j is the state of the i'th row, k is the state of the (i-1)'th row

int main(int argc, char *argv[])
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		broken[x] += 1 << (y - 1);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < (1 << m); j++)
		{
			bool flag1=j & broken[i];
			if (flag1)
			{
				continue;
			}
			for (int k = 0; k < (1 << m); k++)
			{
				bool flag2=(k << 2) & j || (k >> 2) & j || k & broken[i - 1];
				if (!flag2)
				{
					if (i == 2)
					{
						dp[2][j][k] = 1;
					}
					else
					{
						for (int p = 0; p < (1 << m); p++)
						{
							bool flag3=(p << 1) & j || (p >> 1) & j || broken[i - 2] & p;
							if (!flag3)
							{
								dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][p]) % MOD;
							}
						}
					}
				}
			}
		}
	}
	int output = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		for (int j = 0; j < (1 << m); j++)
		{
			output = (output + dp[n][i][j]) % MOD;
		}
	}
	printf("%d", output);
}
/*
3 3 1
1 1
*/