/**
 * Created by DearDeer on 2020/10/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int n;
vector<int> v;

bool isDivisible(int num, int i) {
    for(int j = 0; j < n; ++j) {
        if((i != j) && (num % v[j] == 0)) {
            return false;
        }
    }
    return true;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        v.push_back(d);
    }

    int cnt = 0;

    for(int i = 0; i < n; ++i){

        if(isDivisible(v[i], i)) {
            cnt++;
        }

    }

    cout << cnt << endl;
    
    return 0;
}