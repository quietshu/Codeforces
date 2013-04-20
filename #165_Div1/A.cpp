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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

bool del[100010];
int n, k, top;
long long a;
pair<int, long long> b[100010];

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%d%I64d", &b[i].first, &b[i].second);
	sort(b + 1, b + 1 + n);
	top = 0;
	rep(i, n)
		if(top && b[i].first == b[top].first)
			b[top].second += b[i].second, del[i] = 1;
		else
			top = i;
	top = 0;
	rep(i, n)
		if(!del[i])
			b[++top] = b[i];
	n = top;
	rep(i, n - 1){
		while(b[i + 1].first != b[i].first && b[i].second > 1){
			b[i].second = (b[i].second + 3) / 4;
			b[i].first++;
		}
		b[i + 1].second = max(b[i + 1].second, b[i].second);
	}
	while(b[n].second > 4){
		b[n].second = (b[n].second + 3) / 4;
		b[n].first++;
	}
	cout << b[n].first + 1 << endl;
	return 0;
}

