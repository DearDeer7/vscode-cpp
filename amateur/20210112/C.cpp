/**
 * Combinations(n, d)
 * 从ｎ个元素选择ｄ个组成一个组合
 * 求所有组合
 * Created by DearDeer on 2021/01/12
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<vector<int>> Combinations(vector<int>& nums, int d) {
    vector<vector<int>> ans; // 储存组合结果
    vector<int> cur; // 当前组合

    function<void(int, int)> dfs = [&] (int depth, int s) {
        if(depth == d) {
            for(int i : cur) cout << i;
            cout << endl;
            ans.push_back(cur);
            return;
        }

        for(int i = s; i < nums.size(); ++i) { // 从s位置开始遍历
            cur.push_back(nums[i]);
            dfs(depth + 1, i + 1);
            cur.pop_back();
        }
    };

    dfs(0, 0);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums{1,2,3,4};
    int d = 3;

    Combinations(nums, d);
    
    return 0;
}