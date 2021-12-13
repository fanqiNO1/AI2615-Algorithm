#include <iostream>
using namespace std;
struct Item
{
	int weight;
	int value;
};
int main(int argc, char *argv[])
{
	int n,W;
	scanf("%d %d",&n,&W);
	Item* items=new Item[n+1]{};
	int* K=new int[W+1];
	for(int i=1;i<n+1;i++)
	{
		scanf("%d %d",&items[i].weight,&items[i].value);
	}
	for(int i=0;i<W+1;i++)
	{
		K[i]=0;
	}
	for(int j=1;j<n+1;j++)
	{
		for(int w=W;w>=1;w--)
		{
			if(items[j].weight>w)
			{
				continue;
			}
			else
			{
				K[w]=max(K[w],K[w-items[j].weight]+items[j].value);
				//printf("K[%d]=%d\n",w,K[w]);
			}
		}
	}
	printf("%d",K[W]);
}