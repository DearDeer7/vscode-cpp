/**
 * Created by DearDeer on 2021/01/14
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int gcd(int a,int b) { return b?gcd(b,a%b):a; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << gcd(2,3) << endl;
    
    return 0;
}