#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;
pair<int, int> s[100010];

int main(){
    scanf("%d%d", &n, &k);
    rep(i, n)
        scanf("%d%d", &s[i].first, &s[i].second);
    sort(s + 1, s + 1 + n);
    int top = s[1].first, len = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i].first >= top)
            len += s[i].second - s[i].first + 1, top = s[i].second + 1;
        else
            len += s[i].second - top + 1, top = s[i].second + 1;
    }
    printf("%d\n", int(ceil(double(len) / k)) * k - len);
    return 0;
}
