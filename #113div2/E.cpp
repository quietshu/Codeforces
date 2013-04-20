#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

const int mod = 1000000007;

int n, f[4][2];

int main(){
	scanf("%d", &n);
	f[3][0] = 1;
	rep(i, n)
		rep(j, 4){
			f[j - 1][i & 1] = 0;
			rep(k, 4)
				if(j != k)
					f[j - 1][i & 1] = (f[j - 1][i & 1] + f[k - 1][!(i & 1)]) % mod;
		}
	cout << f[3][n & 1] << endl;
	return 0;
}
