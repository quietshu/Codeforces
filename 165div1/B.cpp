/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : cf.cpp
*	Creation Time : 2013/02/01 23:26:38
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, t, tmp, s[5010], q[5010];
pair<double, int> p[5010];

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%d%lf", &p[i].second, &p[i].first);
	sort(p + 1, p + 1 + n);
	rep(i, n)
		s[i] = p[i].second;
	t = 0;
	rep(i, n){
		tmp = (upper_bound(q + 1, q + 1 + t, s[i]) - q) - 1;
		if(tmp == t)
			q[++t] = s[i];
		else
			q[tmp + 1] = min(q[tmp + 1], s[i]);
	}
	cout << n - t << endl;
	return 0;
}
