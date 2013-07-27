/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.03
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

int n, k, m = 10000;
bool can[100][300];

int main(){
	scanf("%d%d", &n, &k);
	can[0][0] = 1;
	rep(i, n)
		rep(j, k){
			if(j >= 3)
				can[i][j] |= can[i - 1][j - 3];
			if(j >= 4)
				can[i][j] |= can[i - 1][j - 4];
			if(j >= 5)
				can[i][j] |= can[i - 1][j - 5];
		}
	for(int i = 0; i <= n; ++i) if(k >= 2 * i)
		if(can[n - i][k - 2 * i]){
			cout << i << endl;
			return 0;
		}
	cout << 0 << endl;
}

