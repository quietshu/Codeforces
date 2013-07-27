#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    if(n < k || (n > 1 && k == 1)){
        puts("-1");
        return 0;
    }
    bool f = 0;
    for(int i = 1; i <= min(n, n - k + 2); ++i)
        printf("%c", f ? 'b' : 'a'), f = !f;
    for(int i = 1; i <= k - 2; ++i)
        printf("%c", char('b' + i));
    puts("");
    return 0;
}
