/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;
const in M = 1e7+7;
int nums[M];

void dfs(int n, int k, int sum, vector<int>& curr) {
    if(k == 0) {
        if(sum == 0) {
            for(int e: curr) cout << e << " ";
            cout << endl;
        }
    }
    dfs(n, k, sum, curr);
    dfs(n, k - 1, sum - nums[i])
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> curr;
    dfs(n, k);
    
    return 0;
}