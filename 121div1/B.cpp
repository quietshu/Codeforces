/*
* Copyright (C) 2012 All rights reserved.
* File name:  B.cpp
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
#define MAXN 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;
long long b, sum[MAXN + 10], s[MAXN + 10], pos[MAXN + 10];
pair<long long, int> data[MAXN + 10];

bool check(int m){/*
	for(i = n; i; --i) if(data[i].second != m && data[i].second != n){
		sum += data[i].first; t++;
		if(sum + s[m] > b) break;
	}
	return t < k && sum + s[m] > b;*/
	int l = 1, r = n, mid, tmp = 0;
	while(l <= r){
		mid = (l + r) >> 1;
		if(mid <= pos[m]){
			if(sum[mid] > b)
				l = mid + 1, tmp = max(tmp, mid);
			else
				r = mid - 1;
		}
		else{
			if(sum[mid] + s[m] > b)
				l = mid + 1, tmp = max(tmp, mid);
			else
				r = mid - 1;
		}
	}
	return n - tmp + 1 < k && sum[tmp] + (pos[m] < tmp ? s[m] : 0) > b;
}

int main(){
	scanf("%d%d%I64d", &n, &k, &b);
	rep(i, n){
		scanf("%I64d", &data[i].first);
		data[i].second = i;
		s[i] = data[i].first;
		if(s[i] > b){
			cout << i << endl;
			return 0;
		}
	}
	sort(data + 1, data + 1 + n);
	rep(i, n)
		pos[data[i].second] = i;
	for(int i = n; i; --i){
		sum[i] = sum[i + 1];
		if(data[i].second != n)
			sum[i] += data[i].first;
	}
	rep(i, n)
		if(check(i)){
			cout << i << endl;
			return 0;
		}
	cout << n << endl;
	return 0;
}

