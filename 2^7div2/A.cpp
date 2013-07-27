/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.03
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
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int main(){
	int x, t, a, b, da, db;
	cin >> x >> t >> a >> b >> da >> db;
	rep(i, t)
		rep(j, t)
			if(x == a + b - da * (i - 1) - db * (j - 1) || !x || x == a - da * (i - 1) || x == b - db * (i - 1)){
				puts("YES");
				exit(0);
			}
	puts("NO");
}
