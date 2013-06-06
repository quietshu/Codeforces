/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/04/23 00:32:32
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

long long n, fn;
long long fact[100];

const int prime_n = 5;
const int prime[prime_n] = {2, 3, 7, 61, 24251};

long long gcd(long long a, long long b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

long long modplus(const long long &a, const long long &b, const long long & mod){
    long long res = a + b;
    return res < mod ? res : res - mod; 
}

long long modminus(const long long &a, const long long &b, const long long &mod){
    long long res = a - b;
    return res >= 0 ? res : res + mod;
}

long long modmult(const long long &a, const long long &b, const long long &mod){
    long long res = 0;
    long long t = a;
    for (long long i = b; i > 0; i >>= 1) {
        if (i & 1)
            res = modplus(res, t, mod);
        t = modplus(t, t, mod);
    }
    return res; 
}

long long modpow(const long long &a, const long long &b, const long long & mod){
    long long res = 1;
    long long t = a;
    for(long long i = b; i > 0; i >>= 1){
        if(i & 1)
            res = modmult(res, t, mod);
        t = modmult(t, t, mod);
    }
    return res;
}

bool witness(const long long &n, const long long &p){
    long long u = n - 1;
    int t = 0;
    while((u & 1) == 0)
          u >>= 1, t++;
    long long x = modpow(p % n, u, n), last;
    while(t--){
        last = x, x = modmult(x, x, n);
        if(x == 1 && last != 1 && last != n - 1)
            return false;
    }
    return x == 1;
}


bool isPrime(long long n){
    if (n == 1) return false;
    if (find(prime, prime + prime_n, n) != prime + prime_n)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 0; i < prime_n; i++)
        if (!witness(n, prime[i]))
            return false;
    return true;
}

long long getDivisor(const long long &n){
    int c = 1; 
    while(true){
        int i = 1, k = 2; long long x1 = 1, x2 = 1;
        while(true){
            x1 = modplus(modmult(x1, x1, n), c, n);
            long long d = gcd(modminus(x1, x2, n), n);
            if (d != 1 && d != n)
                return d;
            if (x1 == x2)
                break;
            i++;
            if (i == k)
                x2 = x1, k <<= 1;
        }
        c++;
    }
}

void getFactor(long long n){
    if(isPrime(n))
        fact[++fn] = n;
    else{
        long long d = getDivisor(n);
        getFactor(d);
        getFactor(n / d);
    }
}

long long ans, res;
long long f[100], t[100], ch[100], tn, m;

void solve3(int p, long long num){
    if(p > tn) return;
    for(int i = 0; i <= t[p] - ch[p]; ++i){
        solve3(p + 1, num);
        num *= f[p];
        if(i < t[p] - ch[p] && num >= m){
            long long tmp = n / num;
            tmp /= m;
            if(tmp < num)
                return;
            if(!((tmp + num + m) & 1) && m + num > tmp){
                if(m != num && num != tmp)
                    ans += 6;
                else if(m != num)
                    ans += 3;
                else if(num != tmp)
                    ans += 3;
                else
                    ans++;
            }
        }
    }
}

void solve2(long long num){
    m = num;
    solve3(1, 1);
}

void solve(int p, long long num){
    long long tmp = num * num * num;
    if(tmp > n)
        return;
    if(p > tn)
        return;
    for(int i = 0; i <= t[p]; ++i){
        solve(p + 1, num);
        ch[p]++;
        num *= f[p];
        if(num * num * num > n)
            break;
        if(i < t[p])
            solve2(num);
    }
    ch[p] = 0;
}

int main(){
    cin >> n;
    if(n < 24 || n % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    n /= 3;

    getFactor(n);
    sort(fact + 1, fact + 1 + fn);
    rep(i, fn)
        if(fact[i] == fact[i - 1])
            ++t[tn];
        else
            f[++tn] = fact[i], t[tn] = 1;

    solve(1, 1);

    cout << ans << endl;
    return 0;
}
