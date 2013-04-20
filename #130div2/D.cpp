/*
* Copyright (C) 2012 All rights reserved.
* Author:     Parabola_ds
* Creat time: 2012.07.11
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

int n, p[100], s[10];
long long num[100], tot;

int main(){
	scanf("%d", &n);
	rep(i, n)
		scanf("%d", &p[i]);
	rep(i, 5)
		scanf("%d", &s[i]);
	rep(i, n){
		tot += p[i];
		for(int j = 5; j; --j)
			if(tot >= s[j]){
				num[j] += tot / s[j];
				tot -= (tot / s[j]) * s[j];
			}
	}
	rep(i, 5)
		cout << num[i] << " ";
	cout << endl;
	cout << tot << endl;
}
