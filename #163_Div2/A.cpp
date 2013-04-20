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

int n, l;
char s[100];

int main(){
	scanf("%d", &l); n = 0;
	scanf("%s", s);
	rep(i, l - 1)
		if(s[i - 1] == s[i])
			n++;
	cout << n << endl;
	return 0;
}
