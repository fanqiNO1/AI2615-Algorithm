#include <cstdio>
#include <algorithm>
#include <cstring>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> cd;
typedef unsigned long long ull;
#define maxLength 900001
#define PI 3.14159265358979
cd a[maxLength];
cd b[maxLength];
int rev[maxLength];
void get_rev(int bit)
{
	for (int i = 0; i < (1 << bit); i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}
void FFT(cd *a, int n, int dft)
{
	for (int i = 0; i < n; i++)
		if (i < rev[i])
			swap(a[i], a[rev[i]]);
	for (int step = 1; step < n; step <<= 1)
	{
		cd wn = exp(cd(0, dft * PI / step));
		for (int j = 0; j < n; j += step << 1)
		{
			cd wnk(1, 0);
			for (int k = j; k < j + step; k++)
			{
				cd x = a[k];
				cd y = wnk * a[k + step];
				a[k] = x + y;
				a[k + step] = x - y;
				wnk *= wn;
			}
		}
	}
	if (dft == -1)
		for (int i = 0; i < n; i++)
			a[i] /= n;
}

ull output[maxLength];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	n++;
	m++;
	//printf("%d %d",n,m);
	int s = 2, bit = 1;
	for (bit = 1; (1 << bit) < n + m - 1; bit++)
		s <<= 1;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d",&x);
		a[n-i-1] = (double)(x);
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d",&x);
		b[m-i-1]=(double)(x);
	}
	get_rev(bit);
	FFT(a, s, 1);
	FFT(b, s, 1);
	for (int i = 0; i < s; i++)
	{
		a[i] *= b[i];
	}
	FFT(a, s, -1);
	for (int i = 0; i < s; i++)
	{
		output[i] += (ull)(round(a[i].real()));
	}
	bool isHappen=false;
	for(int i=n+m-2; i>=0;i--)
	{
		isHappen=true;
		printf("%llu ",output[i]);
	}
	if(!isHappen)
	{
		printf("0");
	}
	return 0;
}