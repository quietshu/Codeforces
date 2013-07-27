/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : .cpp
*	Creation Time : 2013/01/22 23:28:10
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, t;
char s[100], p[100];

int main(){
	scanf("%d%d", &n, &t);
	scanf("%s", s);
	while(t--){
		memcpy(p, s, sizeof s);
		rep(i, n - 1)
			if(p[i] == 'G' && p[i - 1] == 'B')
				s[i] = 'B', s[i - 1] = 'G';
	}
	printf("%s\n", s);
	return 0;
}
