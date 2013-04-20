/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.04
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define pos(x, y) ((x - 1) * m + y)
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct edge{
	int t, f, next;
	edge(){}
	edge(int t, int f, int n):
		t(t), f(f), next(n){}
} e[10000];

const int inf = 10000;
int n, m, sum, S, T, ans = 10000;
int etop, st[10000], h[10000], hn[10000];
char c[100][100];

void add(int s, int t){
	e[++etop] = edge(t, 1, st[s]);
	st[s] = etop;
	e[++etop] = edge(s, 1, st[t]);
	st[t] = etop;
}

int sap(int v, int lim){
	if(v == T || !lim) return lim;
	int left = lim, f, tmp = sum - 1;
	for(int i = st[v]; i; i = e[i].next){
		if(e[i].f && h[v] == h[e[i].t] + 1){
			f = sap(e[i].t, min(left, e[i].f));
			left -= f;
			e[i].f -= f;
			e[i + (i & 1 ? 1 : -1)].f += f;
			if(h[S] == sum)
				return lim - left;
		}
		if(e[i].f)
			tmp = min(tmp, h[e[i].t]);
	}
	if(lim == left){
		hn[h[v]]--;
		if(!hn[h[v]])
			h[S] = sum;
		else{
			h[v] = tmp + 1;
			hn[h[v]]++;
		}
	}
	return lim - left;
}

int maxFlow(int s, int t){
	if(s == t) return inf;
	S = s, T = t;
	rep(i, etop) e[i].f = 1;
	int f = 0;
	hn[0] = sum;
	memset(h, 0, sizeof(h));
	while(h[s] != sum)
		f += sap(s, inf);
	return f;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n)
		rep(j, m){
			scanf("%c", &c[i][j]);
			while(c[i][j] != '#' && c[i][j] != '.') c[i][j] = getchar();
			if(c[i][j] == '#'){
				sum++;
				if(c[i][j - 1] == '#')
					add(pos(i, j), pos(i, j - 1));
				if(c[i][j + 1] == '#')
					add(pos(i, j), pos(i, j + 1));
				if(c[i - 1][j] == '#')
					add(pos(i, j), pos(i - 1, j));
				if(c[i + 1][j] == '#')
					add(pos(i, j), pos(i + 1, j));
			}
		}
	int tot = 0;
	rep(xs, n)
		rep(ys, m) if(c[xs][ys] == '#')
			rep(xt, n) 
				rep(yt, n) if(c[xt][yt] == '#') if(pos(xs, ys) <= pos(xt, yt) && tot <= 500){
					ans = min(ans, maxFlow(pos(xs, ys), pos(xt, yt)));
					tot++;
				}
	cout << ans << endl;
	return 0;
}

