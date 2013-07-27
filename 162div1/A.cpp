/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/01/20 20:28:18
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

char s[1000010];
int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		if(s[i] == 'r') printf("%d\n", i + 1);
	for(int i = n - 1; i >= 0; --i)
		if(s[i] == 'l') printf("%d\n", i + 1);
	return 0;
}
