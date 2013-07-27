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

int n, t, a[100010], tot, top = 1, num = 0;

int main(){
	scanf("%d%d", &n, &t);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n){
		while(tot + a[i] > t)
			tot -= a[top++];
		tot += a[i];
		num = max(num, i - top + 1);
	}
	cout << num << endl;
	return 0;
}
