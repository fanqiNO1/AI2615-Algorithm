#include <iostream>
using namespace std;
const int MIN=0x3f3f3f3f;
struct Data
{
	int num;
	int sum;
	int maxSum;
};
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	Data* data=new Data[n];
	int sum=0;
	int maxSum=-MIN;
	int min=MIN;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i].num);
		sum+=data[i].num;
		data[i].sum=sum;
		data[i].maxSum=max(data[i].sum,data[i].sum-min);
		if(data[i].maxSum>maxSum)
		{
			maxSum=data[i].maxSum;
		}
		if(data[i].sum<min)
		{
			min=data[i].sum;
		}
	}
	printf("%d",maxSum);
}
/*
7
2 -4 3 -1 2 -4 3
*/