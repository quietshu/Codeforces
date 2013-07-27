/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/01/28 22:32:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[1000], b[1000], aN[1000], bN[1000];
int tot;

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%d%d", &a[i], &b[i]), bN[b[i]]++;
	rep(i, n)
		tot += bN[a[i]];
	cout << tot << endl;
	return 0;
}
