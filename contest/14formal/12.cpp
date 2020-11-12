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
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        v.push_back(d);
    }
    while(q--) {
        LL p, k;
        cin >> p >> k;
        k--;
        // LL sum = p * v[k] / m;
        // if(sum % 2 == 0) {
        //     cout << p * v[k] % m << '\n';
        // }
        // else {
        //     cout << m - p * v[k] % m << '\n';
        // }
        LL mod = p * v[k] % m;
        LL r = p * v[k] / m;
        // cout << "mod r" << mod << ' ' << r << endl;
        if (mod == 0) cout << ((r % 2 == 0) ? 0 : m ) << '\n';
        else if(r % 2 == 1)
            cout << m - mod << '\n';
        else
            cout << mod << '\n';
    }
    return 0;
}