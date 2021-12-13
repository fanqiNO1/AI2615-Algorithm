#include <iostream>
#include <cstring>
using namespace std;
inline int minOf3(int a,int b,int c)
{
	if((a<=b)&&(a<=c))
	{
		return a;
	}
	else if((b<=a)&&(b<=c))
	{
		return b;
	}
	else if((c<=a)&&(c<=b))
	{
		return c;
	}
}
int E[3001][3001];
int diff(char a,char b,int c)
{
	if(a==b)
	{
		return 0;
	}
	else
	{
		return c;
	}
}
int editingDistance(int m,int n,char str1[],char str2[],int insertAndDelete,int change)
{
	for(int i=0;i<=m;i++)
	{
		E[i][0]=i*insertAndDelete;
	}
	for(int j=0;j<=n;j++)
	{
		E[0][j]=j*insertAndDelete;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			E[i][j]=minOf3(E[i-1][j]+insertAndDelete,E[i][j-1]+insertAndDelete,E[i-1][j-1]+diff(str1[i-1],str2[j-1],change));
		}
	}
	return E[m][n];
}
int main()
{
	char str1[3000]={'\0'};
	char str2[3000]={'\0'};
	int insertAndDelete,change;
	scanf("%d %d",&insertAndDelete,&change);
	scanf("%s",str1);
	scanf("%s",str2);
	int m=strlen(str1);
	int n=strlen(str2);
	printf("%d",editingDistance(m,n,str1,str2,insertAndDelete,change));
}