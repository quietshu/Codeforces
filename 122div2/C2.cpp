/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.04
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
#define pos(x, y) ((x - 1) * m + y)
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, sum, tot, ans = 4;
char c[100][100];
bool check = 0;

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n)
		rep(j, m){
			scanf("%c", &c[i][j]);
			while(c[i][j] != '#' && c[i][j] != '.') c[i][j] = getchar();
		}
	rep(i, n)
		rep(j, m)
			if(c[i][j] == '#'){
				sum = 0;
				tot++;
				if(c[i][j - 1] == '#')
					sum++;
				if(c[i][j + 1] == '#')
					sum++;
				if(c[i - 1][j] == '#')
					sum++;
				if(c[i + 1][j] == '#')
					sum++;
				if(sum) check = 1;
				ans = min(ans, sum);
			}
	if(tot == 1 || (tot == 2 && check)) ans = -1;
	cout << ans << endl;
	return 0;
}

