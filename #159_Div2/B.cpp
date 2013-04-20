/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
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

int n, m;
int f[100][100], g[100][100];

int main(){
	scanf("%d%d", &n, &m);
	f[0][0] = g[0][0] = -1;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			if(i + j > 0){
				if((i + j) % 2 == (m + n) % 2){
					f[i][j] = g[i][j] = -100000;
					if(i){
						f[i][j] = i + j - 1 - f[i - 1][j];
						g[i][j] = i + j - 1 - f[i - 1][j] - 1;
					}
					if(j){
						f[i][j] = max(f[i][j], i + j - 1 - g[i][j - 1] - 1);
						g[i][j] = max(g[i][j], i + j - 1 - g[i][j - 1]);
					}
				}
				else{
					f[i][j] = g[i][j] = -100000;
					if(i){
						f[i][j] = i + j - 1 - f[i - 1][j] - 1;
						g[i][j] = i + j - 1 - f[i - 1][j];
					}
					if(j){
						f[i][j] = max(i + j - 1 - g[i][j - 1], f[i][j]);
						g[i][j] = max(i + j - 1 - g[i][j - 1] - 1, g[i][j]);
					}
				}
			}
	printf("%d\n", max(f[n][m], g[n][m]));
	rep(i, n){
		rep(j, m)
			cout << f[i][j] << " ";
		cout << endl;
	}
	cout << "--" << endl;
	rep(i, n){
		rep(j, m)
			cout << g[i][j] << " ";
		cout << endl;
	}
	return 0;
}
