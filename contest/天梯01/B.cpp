/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    double res = 0.0;
    int flag = 1;
    for(int i = 1; i <= n; ++i) {
        if( i == 1) res += i;
        else res += i * flag * 1.0 / (2 * i - 1) ;
        flag = (flag == 1 ? -1 : 1);
    }

    printf("%.3f\n", res);
    
    return 0;
}