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
    
    int a[5] = {};
    for(int i = 0; i < 5; ++i) cin >> a[i];
    for(int i =0 ;i < 5; i++)
        if(a[i] == 0) cout << i + 1 << endl;
    
    return 0;
}