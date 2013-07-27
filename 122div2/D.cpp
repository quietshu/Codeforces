/*
* Copyright (C) 2012 All rights reserved.
* File name:  D.cpp
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
#include <ctime>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, u, t0;
long long r, a[50], b[50], k[50], p[50], ans = -1000000000000ll;

void dfs(int q){
	if(q > u){
		long long tot = 0;
		rep(i, n)
			tot += a[i] * k[i];
		if(tot > ans) ans = tot;
		return;
	}
	if(clock() - t0 > 3.8 * CLOCKS_PER_SEC) return;
	long long t[31];
	rep(i, n) t[i] = a[i], a[i] ^= b[i];
	dfs(q + 1);
	rep(i, n) a[i] = t[p[i]] + r;
	dfs(q + 1);
	rep(i, n) a[i] = t[i];
}

int main(){
	scanf("%d%d%I64d", &n, &u, &r);
	rep(i, n)
		scanf("%I64d", &a[i]);
	rep(i, n)
		scanf("%I64d", &b[i]);
	rep(i, n)
		scanf("%I64d", &k[i]);
	rep(i, n)
		scanf("%I64d", &p[i]);
	t0 = clock();
	dfs(1);
	cout << ans << endl;
}

