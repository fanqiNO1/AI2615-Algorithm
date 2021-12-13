#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Data
{
	int num;
	int length=0;
};
int longestIncreasing(Data* data,int n)
{
	int maxLength=0;
	for(int i=0;i<n;i++)
	{
		int max=0;
		for(int j=0;j<i;j++)
		{
			if(data[j].num<data[i].num)
			{
				if(data[j].length>max)
				{
					max=data[j].length;
				}
			}
		}
		data[i].length=1+max;
		if(data[i].length>maxLength)
		{
			maxLength=data[i].length;
		}
	}
	return maxLength;
}
int main()
{
	int n;
	scanf("%d",&n);
	Data* data=new Data[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i].num);
	}
	int max=longestIncreasing(data,n);
	printf("%d\n",max);
	int jTemp;
	stack<int> print;
	for(int i=max;i>0;i--)
	{
		int min=100000;
		for(int j=n-1;j>=0;j--)
		{
			if(data[j].length==i)
			{
				if(data[j].num<min)
				{
					jTemp=j;
					min=data[j].num;
				}
			}
		}
		print.push(min);
		n=jTemp;
	}
	while(!print.empty())
	{
		printf("%d ",print.top());
		print.pop();
	}
}