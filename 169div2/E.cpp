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
#include <vector>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, q, u, v, sn, num, tmp, prev, e[100010][3], st[100010], next[100010];
int bel[100010], dis[100010], pos[100010], que[100010], orz[100010], totQue[100010];
bool vst[100010];

int main(){
	scanf("%d%d", &n, &q);
	rep(i, n - 1){
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(u == 1)
			st[++sn] = v;
		e[v][++e[v][0]] = u;
		if(u != 1)
			e[u][++e[u][0]] = v;
	}
	vst[1] = 1;
	pos[1] = ++num;
	rep(i, sn){
		tmp = st[i];
		next[prev = 1] = tmp;
		bel[tmp] = i;
		dis[tmp] = 1;
		pos[tmp] = ++num;
		orz[i] = num;
		while(e[tmp][0] > 1){
			if(e[tmp][1] != prev)
				next[tmp] = e[tmp][1];
			else
				next[tmp] = e[tmp][2];
			prev = tmp;
			tmp = next[tmp];
			bel[tmp] = i;
			dis[tmp] = dis[prev] + 1;
			pos[tmp] = ++num;
		}
	}
	orz[sn + 1] = num + 1;

	int cmd, v, x, d;
	while(q--){
		scanf("%d%d", &cmd, &v);
		if(!cmd){
			scanf("%d%d", &d, &x);
			if(v != 1){
				if(dis[v] > x)
					for(int p = pos[v] - x; p <= n; p += p & -p)
						que[p] += d;
				else{
					for(int p = 1; p <= n; p += p & -p)
						totQue[p] += d;
					for(int p = x - dis[v] + 2; p <= n; p += p & -p)
						totQue[p] -= d;
					if(pos[v] + x - 2 * dis[v] + 1 < orz[bel[v] + 1])
						for(int p = pos[v] + x - 2 * dis[v] + 1; p <= n; p += p & -p)
							que[p] += d;
				}
				if(dis[v] > x || pos[v] + x - 2 * dis[v] + 1 < orz[bel[v] + 1]){
					if(orz[bel[v] + 1] - pos[v] - 1 >= x)
						for(int p = pos[v] + x + 1; p <= n; p += p & -p)
							que[p] -= d;
					else
						for(int p = orz[bel[v] + 1]; p <= n; p += p & -p)
							que[p] -= d;
				}
			}
			else{
				for(int p = 1; p <= n; p += p & -p)
					totQue[p] += d;
				for(int p = x + 2; p <= n; p += p & -p)
					totQue[p] -= d;
			}
		}
		else{
			int ans = 0;
			for(int p = dis[v] + 1; p; p -= p & -p)
				ans += totQue[p];
			for(int p = pos[v]; p; p -= p & -p)
				ans += que[p];
			printf("%d\n", ans);
		}
	}
	return 0;
}

