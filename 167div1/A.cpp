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
#define MAXN 100010
using namespace std;

struct node{
	int l, r, c[2];
	long long h, all;
} t[MAXN * 2];

int n, m, tot = 1;
long long h[MAXN], a, b, ans;

void build(int v, int l, int r){
	t[v].l = l; t[v].r = r; t[v].all = -1;
	if(l == r){
		t[v].h = h[l];
		return;
	}
	int m = (l + r) >> 1;
	build(t[v].c[0] = ++tot, l, m);
	build(t[v].c[1] = ++tot, m + 1, r);
}

long long query(int v, int p){
	if(t[v].l == p && t[v].r == p)
		return t[v].h;
	if(t[v].all != -1){
		t[t[v].c[0]].all = t[t[v].c[0]].h = t[v].all;
		t[t[v].c[1]].all = t[t[v].c[1]].h = t[v].all;
		t[v].all = -1;
	}
	if(p <= (t[v].l + t[v].r) / 2)
		return query(t[v].c[0], p);
	return query(t[v].c[1], p);
}

void modify(int v, long long l, long long r, long long h){
	if(t[v].l == l && t[v].r == r){
		t[v].h = h;
		t[v].all = h;
		return;
	}
	if(t[v].all != -1){
		t[t[v].c[0]].all = t[t[v].c[0]].h = t[v].all;
		t[t[v].c[1]].all = t[t[v].c[1]].h = t[v].all;
		t[v].all = -1;
	}
	long long m = (t[v].l + t[v].r) / 2;
	if(r <= m)
		modify(t[v].c[0], l, r, h);
	else if(l > m)
		modify(t[v].c[1], l, r, h);
	else
		modify(t[v].c[0], l, m, h), modify(t[v].c[1], m + 1, r, h);
}

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%I64d", &h[i]);/*, h[i] = max(h[i], h[i - 1]);
	build(1, 1, n);
	scanf("%d", &m);
	rep(i, m){
		scanf("%I64d%I64d", &a, &b);
		printf("%I64d\n", ans = query(1, a));
		modify(1, 1, a, ans + b);
	}*/
	ans = 0;
	scanf("%d", &m);
	rep(i, m){
		scanf("%I64d%I64d", &a, &b);
		printf("%I64d\n", max(ans, h[a]));
		ans = max(ans, h[a]) + b;
	}
	return 0;
}
