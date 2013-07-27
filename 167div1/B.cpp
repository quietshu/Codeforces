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
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m;
long long ans;
pair<int, int> a[MAXN * 2];

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a % b);
}

long long calc(long long a, long long b){
	long long ret = 1, tmp;
	rep(i, a){
		tmp = i;
		while(tmp % 2 == 0 && b > 0)
			tmp /= 2, b--;
		ret = ret * tmp % m;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i].first), a[i].second = i;
	rep(i, n) scanf("%d", &a[i + n].first), a[i + n].second = i;
	sort(a + 1, a + 1 + n + n);
	scanf("%d", &m);

	ans = 1;
	int t = 1, p, tot;
	for(; t <= 2 * n; t = p){
		p = t + 1;
		tot = 0;
		while(p <= 2 * n && a[p].first == a[t].first){
			if(a[p] == a[p - 1])
				++tot;
			++p;
		}
		ans = ans * calc(p - t, tot) % m;
	}
	cout << ans << endl;
	return 0;
}

