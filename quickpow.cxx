#include <iostream>
using namespace std;
long long mod = 1e9 + 7;
struct matT
{
	long long p[2][2];
	matT(long long a, long long b, long long c, long long d)
	{
		this->p[0][0] = a;
		this->p[0][1] = b;
		this->p[1][0] = c;
		this->p[1][1] = d;
	}
};
matT mul(matT &mat1,matT &mat2)
{
	long long a=(mat1.p[0][0]*mat2.p[0][0]+mat1.p[0][1]*mat2.p[1][0])%mod;
	long long b=(mat1.p[0][0]*mat2.p[0][1]+mat1.p[0][1]*mat2.p[1][1])%mod;
	long long c=(mat1.p[1][0]*mat2.p[0][0]+mat1.p[1][1]*mat2.p[1][0])%mod;
	long long d=(mat1.p[1][0]*mat2.p[0][1]+mat1.p[1][1]*mat2.p[1][1])%mod;
	matT temp(a,b,c,d);
	return temp;
}
matT pow(matT &mat, unsigned long long n)
{
	matT init=mat;
	if(n%2==0)
	{
		mat=mul(mat,mat);
		return pow(mat,n/2);
	}
	else if(n==1)
	{
		return mat;
	}
	else
	{
		n--;
		mat=pow(mat,n);
		return mul(mat,init);
	}
}
int main()
{
	unsigned long long n;
	cin>>n;
	if((n==0)||(n==1))
	{
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		cout<<2;
		return 0;
	}
	matT mat(1,1,1,0);
	mat=pow(mat,n);
	cout<<(mat.p[1][0]+mat.p[1][1])%mod;
}