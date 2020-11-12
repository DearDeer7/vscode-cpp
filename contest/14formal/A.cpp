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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--) {
        int n, k;
        cin >>n >>k;
        vector<int> v;
        string s;
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            cin >> s;

            for (int i = s.size() - 1; i >= 0; ++i){
                    st.push(s[i] - '0');
                if(s[i] == '/') {
                    int d = 0;
                    while(st.size()) {
                        d = d * 10 + st.top();
                        st.pop();
                    }
                    cout <<d <<endl;
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k-1; ++i) {
            cout << v[i] << ' ';
        }
        cout << v[k - 1];
    }
    return 0;
}
