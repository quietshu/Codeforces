#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int n, x, l, r, m, a, ans;

int main(){
	scanf("%d%d", &n, &x);
	rep(i, n){
		scanf("%d", &a);
		if(a < x)
			l++;
		if(a > x)
			r++;
		if(a == x)
			m++;
	}
	if(m == 0){
		ans = abs(l - r);
		if(l >= r)
			ans++;
	}
	else{
		if((n + 1) / 2 > l && (n + 1) / 2 <= l + m)
			ans = 0;
		else{
			if(l >= m + r)
				ans = l - m - r + 1;
			else
				ans = r - l - m;
		}
	}
	cout << ans << endl;
	return 0;
}
