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
#include <vector>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[50];
int ans;
vector<pair<int, int> > add[50];

void build(){
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			for(int k = j; k < i; ++k)
				if(a[j] + a[k] == a[i])
					add[i].push_back(make_pair(j, k));
}

bool ck[50];

void dfs(int v, int num){
	if(num >= ans) return;
	if(v == 1){
		ans = num;
		return;
	}
	for(vector<pair<int, int> >::iterator it = add[v].begin(); it != add[v].end(); ++it)
		if(it->first == it->second){
			ck[it->first] = 1;
			dfs(v - 1, num + !ck[v]);
			ck[it->first] = 0;
		}
		else{
			if(!ck[it->first] && !ck[it->second]){
				ck[it->first] = 1;
				ck[it->second] = 1;
				dfs(v - 1, num + 1 + !ck[v]);
				ck[it->first] = 0;
				ck[it->second] = 0;
			}
			else if(!ck[it->first]){
				ck[it->first] = 1;
				dfs(v - 1, num + !ck[v]);
				ck[it->first] = 0;
			}
			else if(!ck[it->second]){
				ck[it->second] = 1;
				dfs(v - 1, num + !ck[v]);
				ck[it->first] = 0;
			}
			else
				dfs(v - 1, num);
		}
}

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &a[i]);
		if(a[i] % a[1] != 0){
			puts("-1");
			return 0;
		}
	}
	for(int i = n; i; --i) a[i] /= a[1];
	ans = n + 1;
	build();
	ck[n] = 1;
	dfs(n, 1);
	if(ans > n) puts("-1");
	else cout << ans << endl;
	return 0;
}

