#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int n, d, m[1005];
vector<int> dis[1005];

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &m[i]);
		rep(j, m[i]){
			scanf("%d", &d);
			dis[i].push_back(d);
		}
		sort(dis[i].begin(), dis[i].end());
	}
	int n1, n2, tot = 0, pre, next, p1, p2;
	rep(i, n){
		pre = i - 1; if(!pre) pre = n;
		next = i + 1; if(next > n) next = 1;
		p1 = p2 = 0;
		rep(j, m[i] - 1){
			n1 = n2 = 0;
			while(p1 < dis[pre].size() && dis[pre][p1] < dis[i][j - 1])
				++p1;
			while(p1 < dis[pre].size() && dis[pre][p1] >= dis[i][j - 1] && dis[pre][p1] <= dis[i][j])
				++p1, ++n1;
			while(p2 < dis[next].size() && dis[next][p2] < dis[i][j - 1])
				++p2;
			while(p2 < dis[next].size() && dis[next][p2] >= dis[i][j - 1] && dis[next][p2] <= dis[i][j])
				++p2, ++n2;
			tot += n1 != n2;
		}
	}
	cout << tot << endl;
	return 0;
}