#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, d, a[200 * 200];

int main(){
    scanf("%d%d%d", &n, &m, &d);
    rep(i, n)
        rep(j, m){
            scanf("%d", &a[i * m + j - m]);
            if(a[i * m + j - m] % d != a[1] % d){
                puts("-1");
                return 0;
            }
        }
    sort(a + 1, a + 1 + n * m);
    int ans = 0, ret;
    for(int i = 1; i <= n * m; ++i)
        ans += (a[i] - a[1]) / d;
    ret = ans;
    for(int i = 2; i <= n * m; ++i)
        ans += (a[i] - a[i - 1]) / d * (i - 1 - n * m + i - 1), ret = min(ret, ans);
    cout << ret << endl;
    return 0;
}
