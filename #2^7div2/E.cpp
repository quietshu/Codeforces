/*
* Copyright (C) 2012 All rights reserved.
* File name:  E.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.04
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
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct data{
	int r, id;
	bool operator < (const data &d) const{
		return r < d.r;
	}
} rate[MAXN];

int tot, m, n, d, s, x, y, c[MAXN], f[MAXN], l[MAXN];

int main(){
	scanf("%d%d%d", &n, &d, &s);
	int s0 = s;
	rep(i, n){
		scanf("%d%d%d", &c[i], &f[i], &l[i]);
		x += 1 - c[i];
		if(l[i] >= d){
			y++;
			rate[y].r = c[i];
			rate[y].id = i;
		}
	}
	sort(rate + 1, rate + 1 + y);
	if(x <= 0) x = 1;
	for(int i = 1; i <= y && tot < x; ++i)
		if(s >= f[rate[i].id]){
			if(c[rate[i].id])
				tot += 1;
			else
				x--;
			s -= f[rate[i].id];
		}
	if(!tot)
		printf("0 %d\n", s0 - s);
	else
		printf("%d %d\n", n - x + tot, s0 - s);
	return 0;
}

