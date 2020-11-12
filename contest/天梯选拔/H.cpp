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

    int n,x;
    cin >> n >> x;
    unordered_map<int, int> freqs;

    if(n == 0) {
        cout << x << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        freqs[d]++;
    }

    int min_d = 100;
    int ans = 0;

    for(int i = 0; i < 101; i++) {
        if(!freqs[i]) {
            int t = abs(i - x);
            if(t < min_d) {
                ans = i;
                min_d = t;
            }
        }
    }

    cout << ans << endl;
    
    // int x,n;
    // cin >> x >> n;
    // unordered_set<int> nums;

    // if(n == 0) {
    //     cout << x << endl;
    //     return 0;
    // }

    // for(int i = 0; i < n; ++i) {
    //     int d;
    //     cin >> d;
    //     nums.insert(d);
    // }

    // int delta = 1;
    // while(1) {
    //     int t1 = x - delta, t2 = x + delta;
    //     delta++;
    //     if(!nums.count(t1)) {
    //         cout << t1 << endl;
    //         return 0;
    //     }
    //     if(!nums.count(t2)) {
    //         cout << t2 << endl;
    //         return 0;
    //     }
    // }
    
    return 0;
}