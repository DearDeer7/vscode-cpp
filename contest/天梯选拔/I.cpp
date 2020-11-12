/**
 * Created by DearDeer on 2020/10/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    
    double h,l;
    cin >> h >> l;
    double ans = (h * h + l * l) / (2.0 * h);
    printf("%.7f\n", ans - h);
    
    return 0;
}