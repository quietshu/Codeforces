#include <iostream>
using namespace std;

int min(int a, int b, int c){
	int m = a < b ? a : b;
	m = m < c ? m : c;
	return m;
}

int n, k, l, c, d, p, nl, np;

int main(){
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	cout << min(k * l / (nl * n), c * d / n, p / (np * n)) << endl;
}
