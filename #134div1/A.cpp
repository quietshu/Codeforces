#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, tot, f[101], x[101], y[101];

int father(int i){
	return f[i] == i ? i : father(f[i]);
}

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%d%d", &x[i], &y[i]), f[i] = i;
	tot = n;
	rep(i, n)
		rep(j, i - 1)
			if(x[i] == x[j] || y[i] == y[j])
				if(father(i) != father(j))
					f[father(i)] = father(j), tot--;
	printf("%d\n", tot - 1);
	return 0;
}