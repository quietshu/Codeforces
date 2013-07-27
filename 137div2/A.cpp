#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, t, a[MAXN];
bool same = 1;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = k; i <= n; ++i)
		if(a[i] != a[k])
			same = 0;
	if(!same){
		puts("-1");
		return 0;
	}
	t = k;
	while(t && a[t] == a[k]) --t;
	printf("%d\n", t);
	return 0;
}