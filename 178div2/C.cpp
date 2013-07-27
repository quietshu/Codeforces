#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define MOD 1000000007ll
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a[2000], tot, b[2000], t[2000];

long long power(long long a, long long b){
    if(!b) return 1;
    long long tmp = power(a, b / 2);
    tmp = tmp * tmp % MOD;
    if(b & 1) tmp = tmp * a % MOD;
    return tmp;
}

int main(){
    cin >> n >> m;
    rep(i, m) cin >> a[i];
    sort(a + 1, a + 1 + m);
    int sum = 0, top = 0, mul = 1;
    for(int i = 1; i <= m; ++i){
        if(a[i] > top + 1){
            b[++tot] = a[i] - top - 1;
            sum += b[tot];
            if(top != 0)
                for(int j = 1; j < b[tot]; ++j)
                    mul = (mul << 1) % MOD;
        }
        top = a[i];
    }
    if(top < n)
        b[++tot] = n - top, sum += b[tot];
    for(int i = 2; i <= sum; ++i)
        mul = (long long)mul * i % MOD;
    for(int i = 1; i <= tot; ++i)
        for(int j = 1; j <= b[i]; ++j)
            mul = (long long)mul * power(j, MOD - 2) % MOD;
    cout << mul << endl;
    return 0;
}
