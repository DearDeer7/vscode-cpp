/**
 * Created by DearDeer on 2021/04/14/17:01
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 5;
    vector<int> nums(n);
    // int cnt = 0;
    for(int i = 0; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1) nums[j] = 1;
            else nums[j] = 0;
        }
        // cnt++;
        for(int k = n - 1; k >= 0; --k) cout << nums[k];
        cout << endl;
    }
    // cout << cnt << endl;
    
    return 0;
}