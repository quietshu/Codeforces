#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 5) cout << 1 << endl; else
	cout << n % 3 + 1 << endl;
}