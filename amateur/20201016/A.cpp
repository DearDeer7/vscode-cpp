/**
 * Created by DearDeer on 2020/10/16
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> q;
    for(int i = 0; i < 10; ++i) q.push_back(i);

    auto ans = find(q.begin(), q.end(), 7);
    cout << ans - q.begin();
    
    return 0;
}