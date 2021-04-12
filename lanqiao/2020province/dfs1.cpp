/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;
const int M = 10007;
int vis[M];

void dfs(vector<int>& nums, int k, int sum, vector<int>& curr) {
    if(k == 0) {
        if(sum == 0) {
            for(int e : curr) cout << e << " ";
            cout << endl;
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(vis[i]) continue;
        if(nums[i] > sum) break;
        vis[i]++;
        curr.push_back(nums[i]);
        dfs(nums, k - 1, sum - nums[i], curr);
        vis[i]--;
        curr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    vector<int> nums{1,2,2,3,4,5,7};
    int k = 2;
    int sum = 5;
    
    vector<int> curr;
    dfs(nums, k, sum, curr);
    
    return 0;
}