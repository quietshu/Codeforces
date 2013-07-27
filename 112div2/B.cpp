#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

long long n, k, l, r, mid;

bool can(){
	long long tot = mid, p = mid;
	while(tot < n && p > 0){
		p /= k;
		tot += p;
	}
	return tot >= n;
}

int main(){
	cin >> n >> k;
	l = 0; r = n;
	while(l <= r){
		mid = (l + r) / 2;
		if(can())
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
