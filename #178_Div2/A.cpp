#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a[200];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    cin >> m;
    int x, y;
    rep(i, m){
        cin >> x >> y;
        if(x > 1)
            a[x - 1] += y - 1;
        if(x < n)
            a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    rep(i, n)
        cout << a[i] << endl;
    return 0;
}
