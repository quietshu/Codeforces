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

long long ans;
int n, q, l, r, a[200010], num[200010];

int main(){
	scanf("%d%d", &n, &q);
	rep(i, n)
		scanf("%d", &a[i]);
	rep(i, q){
		scanf("%d%d", &l, &r);
		num[l]++;
		num[r + 1]--;
	}
	rep(i, n)
		num[i] += num[i - 1];
	sort(a + 1, a + 1 + n);
	sort(num + 1, num + 1 + n);
	rep(i, n)
		ans += (long long)a[i] * num[i];
	cout << ans << endl;
	return 0;
}

