/*
 * =====================================================================================
 *
 *       Filename:  D.cpp
 *
 *    Description:  D
 *
 *        Version:  1.0
 *        Created:  04/02/2013 00:24:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shu Ding (QuietGalaxy), ds303077135@Gmail.com
 *   Organization:  NONE
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
using namespace std;

char s[100];
int n;

int main(){
    cin >> s >> n;
    int l = strlen(s);
    for(int i = 0; i < l; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = char(s[i] - 'A' + 'a');
        if(int(s[i]) < n + 97){
            s[i] = char(s[i] - 'a' + 'A');
        }
    }
    cout << s << endl;
    return 0;
}
