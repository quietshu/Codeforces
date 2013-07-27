/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
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

struct client{
	long long v;
	int id;
	bool operator < (const client &c) const{
		return v < c.v;
	}
} c[MAXN];

int n, tot, ans[MAXN];
long long d, x, y, a, b;

int main(){
	scanf("%d%I64d%I64d%I64d", &n, &d, &a, &b);
	rep(i, n){
		scanf("%I64d%I64d", &x, &y);
		c[i].v = x * a + y * b;
		c[i].id = i;
	}
	sort(c + 1, c + 1 + n);
	for(int i = 1; i <= n && d >= c[i].v; ++i){
		ans[++tot] = c[i].id;
		d -= c[i].v;
	}
	printf("%d\n", tot);
	rep(i, tot) printf("%d ", ans[i]);
	return 0;
}
