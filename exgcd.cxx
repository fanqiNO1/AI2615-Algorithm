#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll exgcd(ull a,ull b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		 ll re=exgcd(b,a%b,x,y);
		 ll temp=x;
		 x=y;
		 y=temp-(a/b)*x;
		 return re;
	}
}
ull gcd(ull a,ull b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}
int main()
{
	ull a,b,c;
	while(true)
	{
		cin>>a>>b>>c;
		if((a==0)and(b==0)and(c==0))
		{
			break;
		}
		ull g=gcd(a,b);
		if(c%g!=0)
		{
			cout<<"No Answer"<<endl;
		}
		else
		{
			a/=g;
			b/=g;
			c/=g;
			ll x=0,y=0;
			exgcd(a,b,x,y);
			x*=c;
			y*=c;
			while(true)
			{
				if((x>=0)&&(x<b))
				{
					break;
				}
				else if(x<0)
				{
					x+=b;
					y-=a;
				}
				else
				{
					x-=b;
					y+=a;
				}
			}
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}