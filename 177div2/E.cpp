#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n;

int calc(int n){
    if(!n) return 0;
    for(int i = 1; i <= 1000; ++i)
        if(n < (1 << i)){
            int p = n - (1 << (i - 1)) + 1;
            return calc(p) + p * ((1 << (i - 1)) - 1 + (1 << (i - 2))) + (n - 2
                    * p) * ((1 << (i - 2)) - 1);
        }
}

int main(){
    scanf("%d", &n);
    cout << calc(n) << endl;
    return 0;
}
