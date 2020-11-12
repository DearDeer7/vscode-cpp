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
    
    int n;
    cin >> n;

    ll sum = 0;
    sum += (n/500) * 1000 + (n%500)/ 5 * 5;
    cout << sum << endl;
    
    return 0;
}