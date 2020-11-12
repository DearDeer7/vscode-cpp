/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    
    double x;
    cin >> x;
    if(x >= 0)
        printf("f(%.2f) = %.2f\n", x, sqrt(x));
    else 
        printf("f(%.2f) = %.2f\n", x, (x + 1) * (x + 1) + 2 * x + 1.0 / x);    
    
    return 0;
}