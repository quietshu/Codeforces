#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int n, m, o[200000];
bool fail;
char s[100];

bool read(){
	++m; if(m > n) return 0;
	if(o[m])
		return read() && read();
	return 1;
}

void write(){
	++m;
	if(o[m]){
		printf("pair<");
		write();
		printf(",");
		write();
		printf(">");
	}
	else
		printf("int");
}

int main(){
	cin >> n; n = 0;
	while(cin >> s)
		o[++n] = s[0] == 'p';
	m = 0;
	if(read() && m == n){
		m = 0;
		write();
	}
	else
		puts("Error occurred");
	return 0;
}

