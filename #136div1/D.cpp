#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define mod 1000000007
#define inc(x, y) (x = (x + y) % mod)
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, tot, sum;
int f[2][2][2][2], g[2][2];

long long gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

int main(){
	scanf("%d%d", &n, &m);
	long long tmp = (n + 1) * (m + 1);
	tmp = tmp * (tmp - 1) % mod * (tmp - 2) % mod;
	int t = (int)tmp;
	tmp = n + 1; tmp = tmp * (tmp - 1) * (tmp - 2) % mod * (m + 1);
	t = (t - tmp + mod) % mod;
	tmp = m + 1; tmp = tmp * (tmp - 1) * (tmp - 2) % mod * (n + 1);
	t = (t - tmp + mod) % mod;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			t = (t - (gcd(i, j) - 1) * (n - i + 1) * (m - j + 1) % mod * 12 + mod) % mod;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			inc(g[i & 1][j & 1], 1);
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j){
			inc(f[0][0][i & 1][j & 1], g[0][0]);
			inc(f[0][1][i & 1][j & 1 ^ 1], g[0][1]);
			inc(f[1][0][i & 1 ^ 1][j & 1], g[1][0]);
			inc(f[1][1][i & 1 ^ 1][j & 1 ^ 1], g[1][1]);
		}
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j){
			if(i % 2 == 0){
				if(j % 2 == 0){
					inc(sum, f[1][0][0][1]);
					inc(sum, f[1][0][1][1]);
					inc(sum, f[0][1][1][0]);
					inc(sum, f[0][1][1][1]);
					inc(sum, f[1][1][1][0]);
					inc(sum, f[1][1][0][1]);
				}
				else{
					inc(sum, f[1][0][1][0]);
					inc(sum, f[1][0][0][1]);
					inc(sum, f[1][1][0][1]);
					inc(sum, f[1][1][1][1]);
					inc(sum, f[0][0][1][0]);
					inc(sum, f[0][0][1][1]);
				}
			}
			else{
				if(j % 2 == 0){
					inc(sum, f[1][1][1][0]);
					inc(sum, f[1][1][1][1]);
					inc(sum, f[0][0][0][1]);
					inc(sum, f[0][0][1][1]);
					inc(sum, f[0][1][1][0]);
					inc(sum, f[0][1][0][1]);
				}
				else{
					inc(sum, f[1][0][1][0]);
					inc(sum, f[1][0][1][1]);
					inc(sum, f[0][0][1][0]);
					inc(sum, f[0][0][0][1]);
					inc(sum, f[0][1][0][1]);
					inc(sum, f[0][1][1][1]);
				}
			}
		}
	t = (t - sum + mod) % mod;
	cout << t << endl;
	return 0;
}