/*
 * =====================================================================================
 *
 *       Filename:  C.cpp
 *
 *    Description:  C
 *
 *        Version:  1.0
 *        Created:  04/02/2013 00:18:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shu Ding (QuietGalaxy), ds303077135@Gmail.com
 *   Organization:  NONE
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int sum;
double ans;

int main(){
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        sum += x;
        ans = max(ans, sum / double(i));
    }
    printf("%.6lf\n", ans);
}
