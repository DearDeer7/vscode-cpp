// Author: DearDeer
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a,sel;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    int l,r;
    while(q--) {
        cin >> l >> r;
        l--, r--;
        hash.clear();
        sel.clear();
        for(int i = l; i <= r; ++i) {
            int d = a[i];
            hash[d]++; 
        }

        for (int i = l; i <= r; ++i) {
            int d = a[i];
            if(hash[d] == -1)
                continue;
            if(hash[d] % 2 == 0 && hash[d]) {
                sel.push_back(d);
                hash[d] = -1;
            }
        }
        int sum = 0;
        for(int di : sel) {
            sum ^= di;
        }
        cout << sum << '\n';
    }
    return 0;
}