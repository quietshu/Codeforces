/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/08/04 01:04:15
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

char s[1010];
int n, t[100];

int main(){
    cin >> s >> n;
    int l = strlen(s);
    rep(i, l)
        t[s[i - 1] - 'a']++;
    int p = 0;
    rep(i, 26)
        if(t[i - 1])
            ++p;
    if(p > n)
        printf("-1\n");
    else{
        rep(ans, 1000){
            int tot = 0;
            rep(i, 26)
                tot += (t[i - 1] + ans - 1) / ans;
            if(tot <= n){
                cout << ans << endl;
                rep(i, 26)
                    rep(j, (t[i - 1] + ans - 1) / ans)
                        printf("%c", 'a' + i - 1);
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
