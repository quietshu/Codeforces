/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.27
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define MAXN 500000
#define inf 50000000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, ans, f[50][50], l[MAXN + 10];
char s[MAXN + 10][20];

int main(){
	scanf("%d\n", &n);
	rep(i, 26)
		rep(j, 26)
			f[i - 1][j - 1] = -inf;
	rep(i, n){
		cin.getline(s[i], 15);
		l[i] = strlen(s[i]);
		rep(j, 26)
			f[j - 1][s[i][l[i] - 1] - 'a'] = max(f[j - 1][s[i][l[i] - 1] - 'a'], f[j - 1][s[i][0] - 'a'] + l[i]);
		f[s[i][0] - 'a'][s[i][l[i] - 1] - 'a'] = max(f[s[i][0] - 'a'][s[i][l[i] - 1] - 'a'], l[i]);
	}
	rep(i, 26)
		ans = max(ans, f[i - 1][i - 1]);
	cout << ans << endl;
	return 0;
}

