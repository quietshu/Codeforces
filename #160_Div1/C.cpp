/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : C.cpp
*	Creation Time : 2013/01/08 18:34:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

long long ans, n, t, g[100][100], p[100][100];
int num, m, dit[100];

int main(){
	cin >> n >> t;
	n++;
	while(t != 1){
		if(t % 2 != 0){
			cout << 0 << endl;
			return 0;
		}
		num++;
		t >>= 1;
	}
	num++;
	while(n){
		dit[++m] = n & 1;
		n >>= 1;
	}
	p[0][0] = g[0][0] = 1;
	rep(i, m)
		for(int j = 0; j <= num; ++j){
			if(dit[i]){
				g[i][j] = p[i - 1][j];
				if(j >= 1)
					g[i][j] += g[i - 1][j - 1];
			}
			else
				g[i][j] = g[i - 1][j];
			p[i][j] = p[i - 1][j];
			if(j)
				p[i][j] += p[i - 1][j - 1];
		}
	ans = g[m][num];
	if(num == 1)
		ans--;
	cout << ans << endl;
	return 0;
}

