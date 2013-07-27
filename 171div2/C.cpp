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
#include <cmath>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a[100010], l;
int maxPos[100010][20];
bool Inc[100010][20], Dec[100010][20];

void init(){
	l = int(log(n) / log(2));
	rep(i, n)
		maxPos[i][0] = i, Inc[i][0] = 1, Dec[i][0] = 1;
	rep(j, l)
		rep(i, n - (1 << j) + 1){
			maxPos[i][j] = a[maxPos[i][j - 1]] > a[maxPos[i + (1 << (j - 1))][j - 1]] ? maxPos[i][j - 1] : maxPos[i + (1 << (j - 1))][j - 1];
			if(Inc[i][j - 1] && Inc[i + (1 << (j - 1))][j - 1] && a[i - 1 + (1 << (j - 1))] <= a[i + (1 << (j - 1))])
				Inc[i][j] = 1;
			if(Dec[i][j - 1] && Dec[i + (1 << (j - 1))][j - 1] && a[i - 1 + (1 << (j - 1))] >= a[i + (1 << (j - 1))])
				Dec[i][j] = 1;

		}
}

bool checkl(int l, int r){
	int len = int(log(r - l + 1) / log(2));
	return Inc[l][len] && Inc[r - (1 << len) + 1][len];
}

bool checkr(int l, int r){
	int len = int(log(r - l + 1) / log(2));
	return Dec[l][len] && Dec[r - (1 << len) + 1][len];
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	init();
	int l, r, pos, len;
	while(m--){
		scanf("%d%d", &l, &r);
		len = int(log(r - l + 1) / log(2));
		if(a[maxPos[l][len]] > a[maxPos[r - (1 << len) + 1][len]])
			pos = maxPos[l][len];
		else
			pos = maxPos[r - (1 << len) + 1][len];
		puts((checkl(l, pos) && checkr(pos, r)) ? "Yes" : "No");
	}
	return 0;
}
