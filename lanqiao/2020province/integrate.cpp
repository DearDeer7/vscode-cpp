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
    
    // int d, n;
    // int ans = (d + n - 1) / n;

    
    double f = 1.5;
    cout << round(f) << " " << floor(f) << " " << ceil(f) << endl;
    
    return 0;
}