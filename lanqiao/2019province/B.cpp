/**
 * Created by DearDeer on 2021/04/12/22:09
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 2019;
    stack<int> s;
    while(n) {
        s.push(n % 26);
        n /= 26;
    }
    while(s.size()) {
        int e = s.top();
        s.pop();
        cout << char(e - 1 + 'A');
    }
    // BYQ
    cout << 2 * 26 * 26 + 25 * 26 + 'Q' - 'A' + 1; // check
    
    return 0;
}