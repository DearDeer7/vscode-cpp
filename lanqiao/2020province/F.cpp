/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

#define DEER 1
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        if(s >= 60) c1++;
        if(s >= 85) c2++;
    }
    // cout << c1 << c2 << endl;
    int a1 = c1 * 1.0 / n * 100 + 0.5;
    int a2 = c2 * 1.0 / n * 100 + 0.5;
    cout << a1 << "%" <<  endl;
    cout << a2 << "%" << endl;
    
    return 0;
}