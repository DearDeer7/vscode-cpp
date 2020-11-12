/**
 * Created by DearDeer on 2020/10/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x,y;
    cin >> x >> y;
    for(int i = 0; i <= x; i++) {
        if(2 * i + (x - i) * 4 == y) { 
            cout <<  "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}