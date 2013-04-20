#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define MAXN 200010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct node{
    int l, r, c[2];
	double sum, add;
} t[MAXN * 2 + 1];

int num = 1, n, T, x, z, np = 1;

void pushdown(int n){
    int l = t[n].c[0], r = t[n].c[1];
    if(l){
        t[l].add += t[n].add;
        t[r].add += t[n].add;
        t[l].sum += t[n].add * (t[l].r - t[l].l + 1);
        t[r].sum += t[n].add * (t[r].r - t[r].l + 1);
    }
    t[n].add = 0;
}

void add(int n, int l, int r, double x){
    if(t[n].l == l && t[n].r == r){
        t[n].add += x;
        t[n].sum += (r - l + 1) * x;
        return;
    }
    pushdown(n);
    int m = (t[n].l + t[n].r) >> 1;
    if(r <= m)
        add(t[n].c[0], l, r, x);
    else if(l > m)
        add(t[n].c[1], l, r, x);
    else
        add(t[n].c[0], l, m, x), add(t[n].c[1], m + 1, r, x);
    t[n].sum = t[t[n].c[0]].sum + t[t[n].c[1]].sum;
}

void build(int n, int l, int r){
    t[n].l = l;
    t[n].r = r;
    if(l == r)
        return;
    build(t[n].c[0] = ++np, l, (l + r) >> 1);
    build(t[n].c[1] = ++np, (l + r) / 2 + 1, r);
}

double sum(int n, int l, int r){
    if(t[n].l == l && t[n].r == r)
        return t[n].sum;
    pushdown(n);
    int m = (t[n].l + t[n].r) >> 1;
    if(r <= m)
        return sum(t[n].c[0], l, r);
    else if(l > m)
        return sum(t[n].c[1], l, r);
    else
        return sum(t[n].c[0], l, m) + sum(t[n].c[1], m + 1, r);
}

void mv(int n, int l, int r){
    if(t[n].l == l && t[n].r == r){
        t[n].sum = 0;
        return;
    }
    pushdown(n);
    int m = (t[n].l + t[n].r) >> 1;
    if(r <= m)
        mv(t[n].c[0], l, r);
    else if(l > m)
        mv(t[n].c[1], l, r);
    t[n].sum = t[t[n].c[0]].sum + t[t[n].c[1]].sum;
}

int main(){
    scanf("%d", &n);
    build(1, 1, n + 1);
    while(n--){
        scanf("%d", &T);
        if(T == 1){
            scanf("%d%d", &x, &z);
            add(1, 1, x, z);
        }
        else if(T == 2){
            scanf("%d", &x);
            ++num;
            add(1, num, num, x);
        }
        else{
            mv(1, num, num);
            --num;
        }
        printf("%.6lf\n", sum(1, 1, num) / num);
    }
    return 0;
}
