#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, tot = 1;
	cin >> n;
	for(int i = 2; i <= n; ++i)
		tot += (i - 1) * 12;
	cout << tot << endl;
	return 0;
}