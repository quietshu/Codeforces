/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
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

int n, m = 1000000001, mt, mp, t;

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &t);
		if(t < m)
			m = t, mt = 1, mp = i;
		else if(t == m)
			mt = 0;
	}
	if(mt == 1)
		cout << mp << endl;
	else
		puts("Still Rozdil");
}
