/*
* Copyright (C) 2012 All rights reserved.
* File name:  B.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.03
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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, l, r, mid, ind, x[100010], y[100010];
int f[1010][1010];

bool check(int s){
	ind++;
	rep(i, s)
		f[x[i]][y[i]] = ind;
	bool ck;
	rep(i, n - 2)
		rep(j, n - 2){
			ck = 1;
			rep(p, 3)
				rep(q, 3)
					if(f[i + p - 1][j + q - 1] != ind){
						ck = 0;
						break;
					}
			if(ck) return 1;
		}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m)
		scanf("%d%d", &x[i], &y[i]);
	l = 0; r = m + 1;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	if(r < 1 || r > m) puts("-1");
	else printf("%d\n", r);
}

