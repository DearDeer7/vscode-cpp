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
#define MAX 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        int a, sum = 0;
        while(m--) {
            cin >> a;
            sum += a;
        }
        if(n != 0) cout << sum << '\n' << '\n';
        else
            cout << sum << '\n';
    }
    
    return 0;
}