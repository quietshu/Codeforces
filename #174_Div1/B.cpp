#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define MAXN 200010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[MAXN], vst[MAXN][2], P;
long long s[MAXN][2];
bool no[MAXN][2];

long long dfs(int v, bool d){
	if(vst[v][d] == P || s[v][d] > 0)
		return s[v][d];
	vst[v][d] = P;
	if(d){
		if(v + a[v] > n || v + a[v] < 1)
			return s[v][d] = a[v];
		if(v + a[v] == 1 || vst[v + a[v]][!d] == P || no[v + a[v]][!d])
			no[v][d] = 1;
		else
			s[v][d] = a[v] + dfs(v + a[v], !d);
		if(no[v + a[v]][!d])
			no[v][d] = 1;
	}
	else{
		if(v - a[v] > n || v - a[v] < 1)
			return s[v][d] = a[v];
		if(v - a[v] == 1 || vst[v - a[v]][!d] == P || no[v - a[v]][!d])
			no[v][d] = 1;
		else
			s[v][d] = a[v] + dfs(v - a[v], !d);
		if(no[v - a[v]][!d])
			no[v][d] = 1;
	}
	return s[v][d];
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 2; i <= n; ++i){
		P = i;
		if(!vst[i][0])
			dfs(i, 0);
		if(!vst[i][1])
			dfs(i, 1);
	}
	for(int i = 1; i < n; ++i)
		if(no[i + 1][0])
			puts("-1");
		else
			printf("%I64d\n", s[i + 1][0] + i);
	return 0;
}

