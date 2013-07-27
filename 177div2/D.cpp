#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    long long ans = 1;
    for(int i = 1; i < k; ++i)
        ans = ans * k % MOD;
    for(int i = 1; i <= n - k; ++i)
        ans = ans * (n - k) % MOD;
    cout << ans << endl;
    return 0;
}
