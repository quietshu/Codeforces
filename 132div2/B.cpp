#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, tmp, maxR1, minP1, maxP2 = 1000000, A, B;

int main(){
    scanf("%d", &n);
    rep(i, n){
        scanf("%d", &tmp);
        maxR1 = max(maxR1, tmp);
    }
    scanf("%d", &n);
    rep(i, n){
        scanf("%d", &tmp);
        minP1 = max(minP1, tmp);
    }
    scanf("%d", &n);
    rep(i, n){
        scanf("%d", &tmp);
        maxP2 = min(maxP2, tmp);
    }
    scanf("%d%d", &A, &B);
    printf("%.10lf\n", sqrt(double(maxR1 * maxR1) / (double(A) / B * maxP2 / minP1 + 1)));
    return 0;
}
