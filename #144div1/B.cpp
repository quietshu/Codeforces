#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define mod 1000000007
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

long long n, m, k;
long long f[101][10001], c[101][101], po[101][2];

long long power(long long a, long long b){
	if(!b) return 1;
	long long tmp = power(a, b / 2);
	tmp = tmp * tmp % mod;
	if(b & 1) tmp = tmp * a % mod;
	return tmp;
}

int main(){
	cin >> n >> m >> k;
	rep(i, n)
		for(int j = 0; j <= i; ++j)
			if(j == 0 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	f[0][0] = 1;
	for(int i = 0; i <= n; ++i)
		po[i][0] = power(c[n][i], m / n),
		po[i][1] = power(c[n][i], m / n + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= k; ++j)
			for(int p = 0; p <= (j < n ? j : n); ++p)
				f[i][j] = (f[i][j] + f[i - 1][j - p] * po[p][m % n >= i]) % mod;
	cout << f[n][k] << endl;
	return 0;
}