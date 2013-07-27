/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : cf.cpp
*	Creation Time : 2013/02/13 20:57:46
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, odd, num[30];
char s[1010];

int main(){
	scanf("%s", s);
	n = strlen(s);
	rep(i, n)
		num[s[i - 1] - 'a']++;
	rep(i, 26)
		odd += (num[i - 1] & 1);
	if(!odd)
		printf("First\n");
	else
		printf("%s\n", odd & 1 ? "First" : "Second");
	return 0;
}
