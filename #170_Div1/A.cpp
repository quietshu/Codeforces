/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : cf.cpp
*	Creation Time : 2013/02/13 20:57:46
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a[500], tmp;
bool hav[500][500], g[500][500] ,vst[500];

void dfs(int v){
	if(vst[v] == 1) return;
	vst[v] = 1;
	rep(i, n) if(g[v][i])
		dfs(i);
}

int main(){
	bool allzero = 1;
	scanf("%d%d", &n, &m);
	rep(i, n){
		scanf("%d", &a[i]);
		if(a[i]) allzero = 0;
		rep(j, a[i])
			scanf("%d", &tmp), hav[i][tmp] = 1;
	}
	rep(i, n)
		rep(j, n) if(i != j){
			bool check = 0;
			rep(k, m)
				if(hav[i][k] && hav[j][k]){
					check = 1;
					break;
				}
			g[i][j] = check;
		}
	int num = 0;
	rep(i, n)
		if(!vst[i]){
			num++;
			dfs(i);
		}
	if(allzero) num++;
	printf("%d\n", num - 1);
	return 0;
}
