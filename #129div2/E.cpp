/*
* Copyright (C) 2012 All rights reserved.
* File name:  E.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.12
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
#define MAXN 200010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n;
double u[26][MAXN], d[26][MAXN], p;
char s1[MAXN], s2[MAXN]

int main(){
	scanf("%d", &n);
	scanf("%s%s", s1, s2);
	p = 1;
	for(int i = 0; i < n; ++i){
		p *= 0.5;
		u[s1[i] - 'A'][0] += p;
		for(int j = 0; j < 26; ++j)
			u[s1[i] - 'A'][t]
	}
}
