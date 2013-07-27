/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/01/08 18:34:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define MAXN 50
#define MAXP 50
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, p, a[MAXN + 10];
double b[MAXN + 10][MAXN + 10][MAXP * MAXN + 10], c[MAXN + 10][MAXN + 10], d[MAXN + 10][MAXN + 10];

void init(){
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
			c[i][j] = (j == 0 || j == i) ? 1 : c[i - 1][j - 1] + c[i - 1][j];
	int pre;
	for(int i = 1; i <= n; ++i){
		b[i][0][0] = 1;
		for(int j = 1; j <= n; ++j)
			if(j != i)
				for(int l = n; l; --l)
					for(int k = a[j]; k <= n * p; ++k)
						b[i][l][k] += b[i][l - 1][k - a[j]];
		for(int j = 0; j <= n; ++j)
			for(int k = max(0, p - a[i] + 1); k <= p; ++k)
				d[i][j] += b[i][j][k];
	}
}

int main(){
	scanf("%d", &n);
	int s = 0;
	rep(i, n)
		scanf("%d", &a[i]), s += a[i];
	scanf("%d", &p);
	if(s <= p){
		printf("%.10lf\n", double(n));
		return 0;
	}
	init();
	double ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < n; ++j)
			ans += j * d[i][j] / (n - j) / c[n][j];
	printf("%.10lf\n", ans);
	return 0;
}

