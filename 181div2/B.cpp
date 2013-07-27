/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/04/25 23:51:09
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

int n, m, a, b, f[50], num[50], tmp[50];

int fa(int i){
    return f[i] == i ? i : f[i] = fa(f[i]);
}

int main(){
    cin >> n >> m;
    rep(i, n)
        f[i] = i;
    rep(i, m){
        cin >> a >> b;
        f[fa(a)] = fa(b);
    }

    rep(i, n){
        num[fa(i)]++;
        if(num[fa(i)] > 3){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(i, n) tmp[i] = num[i];

    rep(i, n){
        if(tmp[i] == 2){
            bool f = 0;
            rep(j, n){
                if(tmp[j] == 1){
                    tmp[j] = 0;
                    f = 1;
                    break;
                }
            }
            if(!f){
                cout << -1 << endl;
                return 0;
            }
        }
    }


    rep(i, n){
        if(num[i] == 3){
            rep(j, n)
                if(fa(j) == i)
                    cout << j << " ";
                cout << endl;
            
        }
        else if(num[i] == 2){
            rep(j, n)
                if(num[j] == 1){
                    rep(k, n)
                        if(fa(k) == i || fa(k) == j)
                            cout << k << " ";
                    num[j] = 0;
                    break;
                } 
        }
        else if(num[i] == 1){
            rep(j, n) if(j != i && num[j] == 1)
                rep(k, j - 1)
                    if(k != i && num[k] == 1){
                        rep(p, n)
                            if(fa(p) == i || fa(p) == j || fa(p) == k)
                                cout << p << " ";
                        cout << endl;
                        num[i] = 0;
                        num[j] = 0;
                        num[k] = 0;
                        goto PPP;
                    }
PPP:{}
        }
    }
    return 0;
}
