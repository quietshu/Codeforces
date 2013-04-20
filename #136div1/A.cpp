#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[100010], b[100010];

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += a[i] != b[i];
	puts(tot <= 2 ? "YES" : "NO");
	return 0;
}