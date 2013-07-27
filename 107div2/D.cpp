#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;

typedef long long int64;

int64 n, m, k, ans;

int64 power(int64 a, int64 b){
	if(b == 0)
		return 1;
	int64 q = power(a, b / 2);
	q = q * q % mod;
	if(b & 1 == 1)
		q = q * a % mod;
	return q;
}

int main(){
	cin >> n >> m >> k;
	if(k > n)
		ans = power(m, n);
	else if(k == 1)
		ans = power(m, n);
	else if(m == 1)
		ans = 1;
	else if(k == n)
		ans = power(m, (n + 1) / 2);
	else if(k % 2 == 0)
		ans = m;
	else ans = power(m, 2);
	cout << ans;
	return 0;
}
