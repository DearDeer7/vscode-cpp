// Author: DearDeer
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        } 
        int res = 0; 
        for(int d:dp){ 
            res = max(res,d); 
        }
        cout << res << '\n';
    }
    return 0;
}