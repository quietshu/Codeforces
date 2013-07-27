#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if(m < n - 1){
		cout << 2 * k << endl;
		rep(i, k) cout << "1 ";
		rep(i, k) cout << n << " ";
	}
	else if(m == n - 1){
		if(k > 1){
		cout << 2 * k << endl;
		rep(i, k) cout << "1 ";
		cout << n << " ";
		rep(i, k - 1) cout << n + 1 << " ";}
		else{
			cout << 3 << endl << "1 " << n << " " << n + 1 << endl;
		}
	}
	else{
		cout << 2 * k + 1 << endl;
		rep(i, k) cout << "1 ";
		cout << n << " ";
		rep(i, k - 1) cout << n + 1 << " ";
		cout << n + m - 1;
	}
	return 0;
}