/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : D.cpp
*	Creation Time : 2013/01/16 22:31:23
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#define MAXM 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, k, a, b, l;
int ans[MAXM + 10];
set<int> et[MAXM + 10];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i, m){
		scanf("%d%d", &a, &b);
		et[a].insert(b);
		et[b].insert(a);
	}
	int v = 1, w;
	ans[l = 1] = 1;
	while(1){
		w = *et[v].begin();
		if(w == 1){
			set<int>::iterator it = et[v].begin();
			it++;
			w = *it;
		}
		for(set<int>::iterator it = et[v].begin(); it != et[v].end(); ++it)
		{
			if(*it == 1 && l >= k + 1)
				goto ED;
			if(v != 1)
				et[*it].erase(v);
		}
		ans[++l] = w;
		v = w;
	}
ED:{}
	cout << l << "\n" << 1;
	for(int i = 2; i <= l; ++i)
		printf(" %d", ans[i]);
	return 0;
}
