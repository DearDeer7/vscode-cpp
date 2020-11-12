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
#include<functional>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums{0, 1, 2, 3};
    // do {
    //     for(int i : nums)
    //         cout << i << ' ';
    //     cout << '\n';
    // } while (next_permutation(nums.begin(), nums.end()));
    int sz = nums.size();
    vector<int> curr;
    vector<bool> vis(nums.size());
    function<void()> dfs = [&]() {
        if(curr.size() == nums.size())
        {
            for(int d : curr)
                cout << d << ' ';
            cout << '\n';
            return;
        }
        for(int i = 0; i < sz; ++i)
        {
            if(vis[i])
                continue;
            vis[i] = true;
            curr.push_back(nums[i]);
            dfs();
            vis[i] = false;
            curr.pop_back();
        }
    };
    dfs();
    return 0;
}