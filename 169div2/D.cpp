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

int tl, tr, t;
long long l, r, ans, a, b;
bool bitl[100], bitr[100], u, d;

int main(){
	cin >> l >> r;
	while(l){
		bitl[++tl] = l & 1;
		l >>= 1;
	}
	while(r){
		bitr[++tr] = r & 1;
		r >>= 1;
	}
	t = max(tl, tr);
	for(int i = t; i; --i){
		ans <<= 1;
		if(u & d)
			ans++;
		else if(!u && !d && bitl[i] != bitr[i])
			ans++, a = a * 2 + bitl[i], b = b * 2 + bitr[i];
		else if(!u && !d && bitl[i] == 1){
			if(b * 2 >= a * 2 + 1){
				ans++;
				u = 1;
				a = a * 2 + 1;
				b = b * 2;
			}
			else
				a = a * 2 + 1, b = b * 2 + 1;
		}
		else if(!u & !d){
			if(b * 2 >= a * 2 + 1){
				ans++;
				d = 1;
				a = a * 2 + 1;
				b = b * 2;
			}
			else
				a = a * 2, b = b * 2;
		}
		else if(d){
			if(bitr[i])
				ans++, a = a * 2, b = b * 2 + 1;
			else if(a * 2 + 1 <= b * 2)
				ans++, a = a * 2 + 1, b = b * 2;
			else
				ans++, a = a * 2, b = b * 2;
		}
		else{
			if(bitl[i])
				ans++, a = a * 2, b = b * 2 + 1;
			else if(a * 2 + 1 <= b * 2)
				ans++, a = a * 2 + 1, b = b * 2;
			else
				ans++, a = a * 2 + 1, b = b * 2 + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
