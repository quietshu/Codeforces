#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

const int inf = 1000000000;

priority_queue<int> que[30];
char s[100500];
int k, n, f, ans = inf;
bool Cant[30][30];

int main(){
	cin.getline(s, 100100);
	scanf("%d", &k);
	memset(Cant, 0, sizeof(Cant));
	rep(i, k){
		char a, b;
		scanf(" %c%c", &a, &b);
		Cant[a - 'a'][b - 'a'] = Cant[b - 'a'][a - 'a'] = 1;
	}
	n = strlen(s);
	for(int i = 0; i < n; i++){
		f = i;
		for(int j = 0; j < 26; j++)
			if(!Cant[s[i] - 'a'][j] && que[j].size())
				f = min(f, - que[j].top() + i + 1);
		que[s[i] - 'a'].push(i + 2 - f);
		ans = min(ans, f + n - i - 1);
	}
	cout << ans << endl;
	return 0;
}
