/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/12/31 00:09:26
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

struct f{
    int l, r;
    long long a, b, aa, bb, ab, ba;
    void set(long long A, long long B, long long AA, long long BB, long long AB,
            long long BA, int L, int R){
        a = A;
        b = B;
        aa = AA;
        bb = BB;
        ab = AB;
        ba = BA;
        l = L;
        r = R;
    }
} f1, f2, f3;

int k, x, n, m;

char ch(int c){
    if(c == 1)
        return 'A';
    if(c == 2)
        return 'C';
    if(c == 3)
        return 'G';
}

void print(int s, int e, int n, long long cnt){
    if(n == 1)
        printf("%c", ch(s));
    else if(n == 2){
        printf("%c", ch(s));
        printf("%c", ch(e));
    }
    else{
        if(s == 1){
            for(int i = 1; i <= cnt; ++i)
                printf("AC");
            for(int i = 1; i <= n - cnt * 2 - 1; ++i)
                printf("G");
            if(cnt * 2 < n)
                printf("%c", ch(e));
        }
        else if(s != 1){
            printf("%c", ch(s));
            rep(i, cnt)
                printf("AC");
            for(int i = 1; i <= n - cnt * 2 - 1; ++i)
                printf("G");
            if(cnt * 2 + 1 < n)
                printf("%c", ch(e));
        }
    }
    puts("");
}

int main(){
    cin >> k >> x >> n >> m;
    f1.set(1, 0, 0, 0, 0, 0, 1, 1);
    f2.set(0, 1, 0, 0, 0, 0, 2, 2);
    for(int i = 3; i <= k; ++i){
        f3.set(f1.a + f2.a,
               f1.b + f2.b,
               f1.aa + f2.aa + (f1.r == 1 && f2.l == 1),
               f1.bb + f2.bb + (f1.r == 2 && f2.l == 2),
               f1.ab + f2.ab + (f1.r == 1 && f2.l == 2),
               f1.ba + f2.ba + (f1.r == 2 && f2.l == 1),
               f1.l,
               f2.r);
        f1 = f2;
        f2 = f3;
    }
    
    rep(sa, 3)
        rep(ea, 3)
            rep(sb, 3)
                rep(eb, 3){
                    if(sa != ea && n == 1)
                        continue;
                    if(sb != eb && m == 1)
                        continue;
                    long long tot = 0;
                    tot += f3.aa * (ea == 1 && sa == 2);
                    tot += f3.bb * (eb == 1 && sb == 2);
                    tot += f3.ab * (ea == 1 && sb == 2);
                    tot += f3.ba * (eb == 1 && sa == 2);
                    if(tot > x)
                        continue;
                    tot = x - tot;
                    int SA, EA, SB, EB;
                    if(n == 1)
                        SA = EA = 0;
                    else if(n == 2)
                        SA = EA = (sa == 1 && ea == 2);
                    else{
                        SA = 0;
                        if(n & 1){
                            if(sa == 1 || ea == 2)
                                EA = n / 2;
                            else
                                EA = n / 2 - 1;
                        }
                        else{
                            if(sa == 1 && ea == 2)
                                EA = n / 2;
                            else
                                EA = n / 2 - 1;
                        }
                    }
                    if(m == 1)
                        SB = EB = 0;
                    else if(m == 2)
                        SB = EB = (sb == 1 && eb == 2);
                    else{
                        SB = 0;
                        if(m & 1){
                            if(sb == 1 || eb == 2)
                                EB = m / 2;
                            else
                                EB = m / 2 - 1;
                        }
                        else{
                            if(sb == 1 && eb == 2)
                                EB = m / 2;
                            else
                                EB = m / 2 - 1;
                        }
                    }
                    for(long long i = SA; i <= EA; ++i){
                        long long j = tot - i * f3.a;
                        if(j % f3.b != 0)
                            continue;
                        j /= f3.b;
                        if(j >= SB && j <= EB){
                            print(sa, ea, n, i);
                            print(sb, eb, m, j);
                            return 0;
                        }
                    }
                }
    puts("Happy new year!");
    return 0;
}
