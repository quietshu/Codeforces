#include <algorithm>
#include <iostream>
#include <cstdio>
#define MAXN  100010
using namespace std;

int n, x, a[MAXN], b[MAXN];

int main(){
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int pos = 1, r = 0;
    for(int i = n; i; --i){
        while(pos <= n && a[i] + b[pos] < x)
            pos++;
        if(pos <= n && a[i] + b[pos] >= x)
            r++, pos++;
    }
    printf("1 %d\n", r);
    return 0;
}