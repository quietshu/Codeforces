#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int n, m;

int main(){
	cin >> n >> m;
	if(!n && m){
		puts("Impossible");
		return 0;
	}
	cout << n + m - min(n, m) << " " << n + m - (m > 0) << endl;
	return 0;
}

