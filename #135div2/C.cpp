#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 500010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = 100000000;
int n, k, f[MAXN][30], pre[MAXN][30];
char s[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	rep(i, k) f[0][i] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j){
			f[i][j] = inf;
			if(s[i - 1] - 'A' != j - 1){
				for(int t = 1; t <= k; ++t)
					if(t != j && f[i][j] > f[i - 1][t] + 1)
						f[i][j] = f[i - 1][t] + 1, pre[i][j] = t;
			}
			else{
				for(int t = 1; t <= k; ++t)
					if(t != j && f[i][j] > f[i - 1][t])
						f[i][j] = f[i - 1][t], pre[i][j] = t;
			}
		}
	int ans = inf, p;
	for(int i = 1; i <= k; ++i)
		if(f[n][i] < ans)
			ans = f[n][i], p = i;
	printf("%d\n", ans);
	for(int i = n; i; --i)
		s[i - 1] = 'A' + p - 1, p = pre[i][p];
	puts(s);
	return 0;
}