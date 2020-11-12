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
    vector<string> ans{"Donald Trump", "Alan Turing", "Nao Tomori", "Dongpo Su"};
    // string s;
    // int t,n;
    // cin >> t;
    // while(t--) {
    //     cin >> n;
    //     while(n--) {
    //         getline(cin, s);
    //         getline(cin, s);
    //     }
    // }
    vector<int> th{0,3,1,2};
    for(int i = 0; i < 4; ++i) {
        cout << ans[th[i]] << '\n';
    }
    return 0;
}
