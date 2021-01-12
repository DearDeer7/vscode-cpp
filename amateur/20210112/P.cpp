/**
 * Permutations(n, d)
 * 从ｎ个元素选择ｄ个组成一个排列
 * 求所有排列
 * Created by DearDeer on 2021/01/12
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<vector<int>> Permutations(vector<int>& nums, int d) {
    vector<vector<int>> ans; // 储存排列结果

    vector<int> cur; // 当前排列
    vector<int> used(nums.size(), 0); // 访问数组

    function<void(int)> dfs = [&] (int depth) { // dfs生成所有排列
        if(depth == d) {
            for(int i : cur) cout << i;
            cout << endl;
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;
            used[i] = 1;
            cur.push_back(nums[i]);
            dfs(depth + 1);
            cur.pop_back();
            used[i] = 0;
        }
    };

    dfs(0);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums{1,2,3,4};
    int d = 2;
    
    Permutations(nums, d);
    
    return 0;
}