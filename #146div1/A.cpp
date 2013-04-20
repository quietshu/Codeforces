#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

long long n;

long long gcd(long long a, long long b){
	return !b ? a : gcd(b, a % b);
}

int main(){
	cin >> n;
	if(n <= 2)
		cout << n << endl;
	else{
		if(n & 1)
			cout << n * (n - 1) * (n - 2) << endl;
		else{
			long long tmp = n * (n - 1) * (n - 3) / gcd(n, n - 3);
			tmp = max(tmp, (n - 1) * (n - 2) * (n - 3));
			cout << max(n * (n - 1) * (n - 2) / 2, tmp) << endl;
		}
	}
	return 0;
}