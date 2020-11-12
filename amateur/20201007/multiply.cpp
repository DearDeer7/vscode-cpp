/**
 * Created by DearDeer on 2020/10/08
 */
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int T = 1; T <= t; ++T) {
        string a, b;
        cin >> a >> b;
        int az = a.size(), bz = b.size();
        
        vector<int> v(az + bz, 0);

        // v[0] store top ascend number
        // core code
        for(int i = bz-1; i >= 0; --i) {
            for(int j = az-1; j >= 0; --j) {
                int A = a[j] - '0', B = b[i] - '0';
                int tmp = A * B;
                v[i + j + 1] += tmp % 10;
                v[i + j] += tmp / 10;
            }
        }
        for(int i = az + bz - 1; i > 0; --i) {
            v[i - 1] += v[i] / 10;
            v[i] = v[i] % 10; 
        }

        cout << "Case " << T << ":" << endl;
        cout << a << " * " << b << " = ";
        if(v[0] != 0) cout << v[0];
        for(int i = 1; i < v.size(); ++i) {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}