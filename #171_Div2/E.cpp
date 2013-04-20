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

int l, tot;
char s[1000010];

int main(){
	scanf("%s", s);
	l = strlen(s);
	int i = l - 1;
	while(i >= 0){
		if(i > 0 && s[i] == '1' && s[i - 1] == '0')
			tot++;
		else if(i > 0 && s[i] == '1'){
			tot++;
			while(i > 0 && s[i - 1] == '1')
				--i;
			if(i > 0)
				s[i - 1] = '1';
			else
				++tot;
		}
		else if(i == 0)
			tot += s[i] == '1';
		--i;
	}
	cout << tot << endl;
	return 0;
}
