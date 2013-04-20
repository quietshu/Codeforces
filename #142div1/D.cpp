#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, ans, top, h[5001], pre[5001];
long long s[5001], f[5001];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]), s[i] = s[i - 1] + h[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < i; ++j)
			if(f[j] <= s[i] - s[j])
				f[i] = s[i] - s[j], pre[i] = j;
	ans = n;
	while(n)
		n = pre[n], ans--;
	printf("%d\n", ans);
	return 0;
}