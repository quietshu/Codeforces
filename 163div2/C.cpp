/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : .cpp
*	Creation Time : 2013/01/22 23:28:10
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

vector<pair<int, pair<int, int> > > op;
vector<pair<int, int> > data;
int n, x, y, rx[1001], ry[1001], g[1001][1001];
int num[1001], numr[1001];

void solve(int t){
	int pos = t;
	for(int i = t; i <= n; ++i)
		if(num[i] > num[pos])
			pos = i;
	if(t != pos){
		op.push_back(make_pair(2, make_pair(t, pos)));
		swap(num[t], num[pos]);
		swap(ry[t], ry[pos]);
	}
	for(int i = t; i <= n; ++i)
		if(numr[i] == 0){
			if(i != t)
				op.push_back(make_pair(1, make_pair(t, i)));
			swap(numr[t], numr[i]);
			swap(rx[t], rx[i]);
			break;
		}
	for(int i = t; i <= n; ++i)
		if(g[rx[i]][ry[t]])
			numr[i]--;
}

int main(){
	scanf("%d", &n);
	rep(i, n)
		rx[i] = ry[i] = i;
	rep(i, n - 1){
		scanf("%d%d", &x, &y);
		g[x][y] = 1;
		num[y]++;
		numr[x]++;
	}
	rep(i, n - 1)
		solve(i);
	cout << op.size() << endl;
	for(unsigned int i = 0; i < op.size(); ++i)
		printf("%d %d %d\n", op[i].first, op[i].second.first, op[i].second.second);
	return 0;
}
