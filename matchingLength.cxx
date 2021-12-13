#include <iostream>
#include <cstring>
using namespace std;
int matchingLength(char *str)
{
	int n = strlen(str);
	int **dp = new int *[n];
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = new int[n]{};
	}
	for (int m = 1; m < n; m++)
	{
		for (int i = 0; i < n; i++)
		{
			int j = i + m;
			if (j > n)
			{
				break;
			}
			if (((str[i] == '(') && (str[j] == ')')) || ((str[i] == '[') && (str[j] == ']')))
			{
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			for (int k = i; k < j; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	return dp[0][n - 1];
}
int main()
{
	char *str = new char;
	scanf("%s", str);
	printf("%d", matchingLength(str));
}
//([[)]])