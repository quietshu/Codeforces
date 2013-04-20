/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/01/20 20:28:18
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAXN  100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, t, tmp, a[MAXN + 10], m[MAXN + 10], ans;

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n){
		t = 0;
		tmp = a[i];
		for(int j = 2; j * j <= a[i]; ++j)
			if(a[i] % j == 0){
				t = max(t, m[j]);
				while(a[i] % j == 0)
					a[i] /= j;
			}
		if(a[i] != 1)
			t = max(t, m[a[i]]);
		a[i] = tmp;
		t++;
		for(int j = 2; j * j <= a[i]; ++j)
			if(a[i] % j == 0){
				m[j] = max(m[j], t);
				while(a[i] % j == 0)
					a[i] /= j;
			}
		if(a[i] != 1)
			m[a[i]] = max(m[a[i]], t);
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}
