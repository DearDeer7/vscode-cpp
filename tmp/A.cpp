/**
 * Created by DearDeer on 2020/10/24
 */
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a = 0, b = 1;
    while( a = b++) {
        cout << a << endl;
    }
    same to 
    a = b;
    b++;
    while(a) {
        cout << a << endl;
        a = b;
        b++;
    }
    return 0;
}