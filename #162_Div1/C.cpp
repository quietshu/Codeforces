/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : C.cpp
*	Creation Time : 2013/01/20 20:28:18
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <climits>
#define MAXN  100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const long long inf = LONG_LONG_MIN;
int n, q;
long long a, b, tmp, ans = -inf;
long long v[MAXN + 10], c[MAXN + 10];
long long m[MAXN + 10], n1, n2;

int main(){
	scanf("%d%d", &n, &q);
	rep(i, n)
		scanf("%I64d", &v[i]);
	rep(i, n)
		scanf("%I64d", &c[i]);
	rep(i, q){
		scanf("%I64d%I64d", &a, &b);
		rep(i, n + 1)
			m[i] = -inf;
		n1 = 1; n2 = 2;
		ans = 0;
		rep(i, n){
			tmp = v[i] * b;
			if(m[c[i]] != -inf)
			tmp = max(tmp, m[c[i]] + a * v[i]);
			int t = n1 == c[i] ? n2 : n1;
			if(m[t] != -inf)
			tmp = max(tmp, m[t] + (long long)b * v[i]);
			if(tmp > m[c[i]]){
				if(n1 == c[i]);
				else if(n2 == c[i]){
					if(tmp > m[n1])
						n2 = n1, n1 = c[i];
				}
				else if(tmp > m[n1]){
					n2 = n1;
					n1 = c[i];
				}
				else if(tmp > m[n2])
					n2 = c[i];
				m[c[i]] = tmp;
			}
			ans = max(ans, tmp);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

