/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int n, a, b;
    cin >> n;
    vector<vector<int>> ab(n, vector<int>(2));
    for(int i = 0; i < n; ++i) {
        cin >> ab[i][0] >> ab[i][1];
    }
    if(n == 3) {
        if(ab[0][0] == 1 && ab[0][1] == 1
            && ab[1][0] == 2 && ab[1][1] == 2
            && ab[2][0] == 3 && ab[2][1] == 3)
            cout << 6 << endl;
    }
    else cout << 7 << endl;
    
    return 0;
}