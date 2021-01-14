/**
 * Created by DearDeer on 2021/01/14
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    float x = 2.1;
    int y = 0;
    int z = 0;

    y = x;
    z = (x - y) * 10;

    cout << x << " " << y << " " << z << endl;

    y = (int)x;
    z = (int)(x * 10) % 10;
    cout << x << " " << y << " " << z << endl;
    
    return 0;
}