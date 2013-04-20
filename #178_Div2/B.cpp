#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, t[200], w[200], ans = 10000000;
vector<int> T[3];

int main(){
    cin >> n;
    rep(i, n){
        cin >> t[i] >> w[i];
        T[t[i]].push_back(w[i]);
    }
    sort(T[1].begin(), T[1].end());
    sort(T[2].begin(), T[2].end());
    int l1 = 0, l2;
    for(int i = 0; i <= T[1].size(); ++i){
        l2 = 0;
        for(int j = 0; j <= T[2].size(); ++j){
            if((T[1].size() - i) + (T[2].size() - j) * 2 >= l1 + l2)
                ans = min(ans, int((T[1].size() - i) + 2 * (T[2].size() - j)));
            if(j < T[2].size())
                l2 += T[2][j];
        }
        if(i < T[1].size())
            l1 += T[1][i];
    }
    cout << ans << endl;
    return 0;
}
