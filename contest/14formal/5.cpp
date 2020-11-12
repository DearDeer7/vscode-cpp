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

// void fun(vector<int>& v) {
//     int flag = 1;
//     int sz = v.size() - 1;

//     while(flag) {
//         flag = 0;
//         for(int i = 0; i < sz; ++i) {
//             if (v[i] == -1) continue;
//             int vi = v[i];
//             int index = i;
//             while (i < sz && v[i + 1] == -1) i++;
//             if (i >= sz) break;
//             if (vi == v[i + 1]) {continue;}

//             flag = 1;
//             int a = vi % v[i + 1];
//             int b = v[i + 1] % vi;
//             v[index] = -1;
//             v[i + 1] = max(a, b);
//         }
//     }

//     int cnt = 0;
//     for(int i = 0; i < sz + 1; ++i) {
//         if (v[i] != -1) cnt++;
//     }
//     if (cnt == 1) cout << 1 << '\n';
//     else
//         cout << (cnt - 1) / 2 + 1 << '\n';
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        // int cntone = 0;
        while(n--) {
            int d;
            cin >> d;
            // if (d == 1) cntone++;
            v.push_back(d);
        }
        int cnt = 1;
        for(int i = 0; i < v.size() - 1; ++i) {
            if(v[i] == v[i + 1]) {
                cnt++;
            }
            else {
                int a = v[i] % v[i + 1];
                int b = v[i + 1] % v[i];
                v[i + 1] = min(a, b);
                if(v[i] != v[i + 1]) 
                cnt = 1;
            }
        }
        cout << (cnt + 1) / 2 << '\n';
        // if(cntone) {
        //     cout << (cntone + 1) / 2 << '\n';
        //     continue;
        // }
        // vector<int> mod(v.size() * 2, 0);
        // for(i = 0; i < n; ++i) {
        //     int d = v[i] 
        // }

        // // vector<int> a = fun(v);
        // // cout << "a : ";
        // // for (int i : a) cout << i << ' ';
        // // cout << endl;
        // fun(v);

    }
    return 0;
}