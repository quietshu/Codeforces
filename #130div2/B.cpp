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

int n, a[100];
bool f[53][70][70][70][70], ans;
char s[100];

void init(int pos, int A, int b, int c){
    if(f[pos][A][b][c])
        return;
    f[pos][A][b][c] = 1;
    if(pos = 1 && !c){
        if(A / 5 == b / 5 || A % 5 == b % 5)
            ans = 1;
        return;
    }
    if(c / 5 == b / 5 || c % 5 == b % 5){
        if(pos > 1)
            init(pos - 1, a[pos - 1], A, c);
        else
            init(1, A, c, 0);
    }
    if(b / 5 == A / 5 || b % 5 == A % 5){
        if(pos > 1)
            init(pos - 1, a[pos - 1], b, c);
        else
            init(1, b, c, 0);
    }
	if(pos > 2 && (a[pos - 2] / 5 == a[pos - 1] / 5 || a[pos - 2] % 5 == a[pos - 1] % 5))
		init(pos - 2, c, A, b);
    if(pos > 1 && (A / 5 == a[pos - 1] / 5 || A % 5 == a[pos -1] % 5))
        init(pos - 1, A, b, c);
    if(pos > 1 && (c / 5 == a[pos - 1] / 5 || c % 5 == a[pos - 1] % 5))
		init(pos - 1, c, A, b);
}

int main(){
    scanf("%d", &n);
    if(n == 1){
        puts("YES");
        return 0;
    }
    rep(i, n){
        cin >> s;
        if(s[0] >= '2' && s[0] <= '9')
            a[i] = s[0] - '1';
        else
            a[i] = s[0] == 'T' ? 9 : (s[0] == 'J' ? 10 : (s[0] == 'Q' ? 11 : (s[0] == 'K' ? 12 : 13)));
        a[i] = a[i] * 5 + (s[1] == 'S' ? 1 : (s[1] == 'D' ? 2 : (s[1] == 'H' ? 3 : 4)));
    }
    if(n == 2){
        if(a[2] / 5 == a[1] / 5 || a[2] % 5 == a[1] % 5){
            puts("YES");
            return 0;
        }
        puts("NO");
        return 0;
    }
    init(n - 2, a[n - 2], a[n - 1], a[n]);
    puts(ans ? "YES" : "NO");
    return 0;
}

