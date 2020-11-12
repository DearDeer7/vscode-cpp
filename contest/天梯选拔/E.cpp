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
    
    vector<int> v;
    int d;
    int t;
    cin >> t;
    while(t--) {
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    for(int i : v) cout << i << ' ';
    cout << endl;
    
    return 0;
}