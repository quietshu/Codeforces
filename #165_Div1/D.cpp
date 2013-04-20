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
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = 1000000000;

int n, tot, sn, T, l[100010], r[100010], h[100010];
pair<int, int> H[100010], next[100010];
int lr[200010], hl[100010], hr[100010];
map<int, int> hash;

struct node{
	int l, r, m, c[2], p;
} t[100010 * 4];

void build(int n, int l, int r){
	t[n].l = l;
	t[n].r = r;
	t[n].m = 0;
	if(l == r){
		t[n].c[0] = t[n].c[1] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(t[n].c[0] = ++sn, l, m);
	build(t[n].c[1] = ++sn, m + 1, r);
}

void insert(int n, int s, int p, int h){
	if(t[n].l == s && t[n].r == s){
		if(h > t[n].m){
			t[n].m = max(t[n].m, h);
			t[n].p = p;
		}
		else if(h == t[n].m && r[p] - l[p] > r[t[n].p] - l[t[n].p])
			t[n].p = p;
		return;
	}
	if(s <= (t[n].l + t[n].r) / 2)
		insert(t[n].c[0], s, h);
	else insert(t[n].c[1], s, h);
	t[n].m = max(t[t[n].c[0]].m, t[t[n].c[1]].m);
}

pair<int, int> query(int n, int l, int r){
	if(t[n].l == l && t[n].r == r)
		return make_pair(t[n].m, t[n].p);
	int m = (t[n].l + t[n].r) / 2;
	if(r <= m)
		return query(t[n].c[0], l, r);
	if(l > m)
		return query(t[n].c[1], l, r);
	pair<int, int> a = query(t[n].c[0], l, m), b = query(t[n].c[1], m + 1, r);
	if(a.first > b.first) return a;
	if(a.first < b.first) return b;
	if(r[a.second] - l[a.second] > r[b.second] - l[b.second]) return a;
	return b;
}

void solveLR(){
	rep(i, n)
		hl[i] = hash[l[H[i].second]], hr[i] = hash[r[H[i].second]];
	sn = 1;
	build(1, 1, tot);
	rep(i, n){
		pair<int, int> tmp = query(1, hl[i], hr[i]);
		if(next[i].first < tmp.first)
			next[i] = tmp;
		else if(next.first == tmp.first && r[next.second] - l[next.second] < r[tmp.second] - l[tmp.second])
	}
}

int main(){
	scanf("%d%d", &n, &T);
	rep(i, n){
		scanf("%d%d%d", &h[i], &l[i], &r[i]);
		H[i] = make_pair(h[i], i);
		next[i] = make_pair(0, n + 2);
		lr[i * 2 - 1] = l[i];
		lr[i * 2] = r[i];
	}
	sort(lr + 1, lr + 1 + n * 2);
	for(int i = 1; i <= n; ++i)
		if(lr[i] != lr[tot])
			lr[++tot] = lr[i];
	rep(i, tot)
		hash[lr[i]] = i;
	l[n + 1] = l[n + 2] = -inf;
	r[n + 1] = r[n + 2] = inf;
	h[n + 1] = T;
	h[n + 2] = 0;
	sort(H + 1, H + 1 + n);
	solveLR();
	return 0;
}
