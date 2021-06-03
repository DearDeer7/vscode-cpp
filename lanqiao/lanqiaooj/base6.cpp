/**
 * Created by DearDeer on 2021/04/14/20:47
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const double PI = atan(1.0)*4;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 10; i <= 99; ++i) {
        int a = i % 10, b = i / 10;
        int left = n - (a + b) * 2;
        for(int j = 0; j <= 9; ++j) {
            if(left == j) {
                cout << i << j << a << b << endl;
            }
        }
    }

    for(int i = 100; i <= 999; ++i) {
        int a = i % 10, b = i / 10 % 10, c = i / 100;
        if((a + b + c) * 2 == n) cout << i << a << b << c << endl;
    }
    
    return 0;
}