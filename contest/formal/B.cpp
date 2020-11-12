/**
 * Created by DearDeer on 2020/10/13
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<pair<int,int>,char> m;
    m[{1,2}] = 'a';
    m[{2,3}] = 'b';
    m[{3,4}] = 'c';

    for(auto i : m) {
        cout << i.first.second << i.second << endl;
    }
    
    return 0;
}