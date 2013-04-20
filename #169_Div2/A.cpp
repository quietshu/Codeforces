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
using namespace std;

int n, k, f, t, ans = -1000000000;

int main(){
	scanf("%d%d", &n, &k);
	rep(i, n){
		scanf("%d%d", &f, &t);
		if(t > k)
			ans = max(ans, f - t + k);
		else
			ans = max(ans, f);
	}
	cout << ans << endl;
	return 0;
}
