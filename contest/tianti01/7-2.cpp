/**
 * Created by DearDeer on 2020/11/02
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    double w,h;
    cin >> w >> h;
    double ans = w / (h*h);
    printf("%.1f\n",ans);
    
    cout << (ans > 25.0 ? "PANG" : "Hai Xing") << endl;
    
    return 0;
}