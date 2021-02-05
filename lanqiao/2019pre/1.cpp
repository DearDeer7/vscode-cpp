/**
 * http://oj.ecustacm.cn/problem.php?id=1452
 * Created by DearDeer on 2021/02/05
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

bool check(int i) {
    while(i) {
        int mod = i % 10;
        i /= 10;
        if(mod == 2 || mod == 0 || mod == 1 || mod == 9) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long sum = 0;
    for(int i = 1; i <= 2019; ++i) {
        if(check(i)) {
            sum += i * i;
        }
    }
    cout << sum << endl;
    
    return 0;
}