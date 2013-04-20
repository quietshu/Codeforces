/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : .cpp
*	Creation Time : 2013/01/22 23:28:10
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a, b, c, g[201][201];
double ans = 0;
bool vst[201];

void dfs(int v, double l){
	if(l > ans)
		ans = l;
	vst[v] = 1;
	rep(i, n)
		if(g[v][i] && !vst[i])
			dfs(i, l + g[v][i]);
	vst[v] = 0;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
	}
	rep(i, n)
		dfs(i, 0);
	printf("%.10lf\n", ans / 2);
	return 0;
}
