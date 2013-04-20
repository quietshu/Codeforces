/*
* Copyright (C) 2012 All rights reserved.
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

char s[1000];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	bool w = 0, l = 0;
	for(int i = 0; i < len; ++i){
		if(i + 2 < len && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
			i += 2, w = 1;
		else{
			if(l && w)
				printf(" ");
			printf("%c", s[i]);
			l = 1;
			w = 0;
		}
	}
	return 0;
}
