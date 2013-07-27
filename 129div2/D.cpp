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
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int cl[MAXN], cr[MAXN], n, top = 1, top2, ans = 1000000001;

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &cl[i], &cr[i]);
		if(cl[i] == cr[i])
			cr[i] = -cr[i];
	}
	sort(cl + 1, cl + 1 + n);
	sort(cr + 1, cr + 1 + n);
	for(int i = 1; i <= n; ){
		int j;
		for(j = i; cl[j] == cl[i] && j <= n; ++j);
		while(cl[i] > cr[top] && top <= n) top++;
		if(cl[i] == cr[top]){
			for(top2 = top; cr[top2] == cr[top] && top2 <= n; ++top2);
			if(cl[i] == cr[top] && 2 * (j - i + top2 - top) >= n)
				ans = min(ans, max(0, (n + 1) / 2 - j + i));
			top = top2;
		}
		if((j - i) * 2 >= n)
			ans = min(ans, max(0, (n + 1) / 2 - j + i));
		i = j;
	}
	printf("%d\n", ans > 1e9 ? -1 : ans);
}

