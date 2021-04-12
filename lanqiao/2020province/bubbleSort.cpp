/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // 检验J题结果
    string s;
    cin >> s;
    vector<int> nums;
    for(char c : s) nums.push_back(c - 'a');
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    for(int e : nums) cout << char(e + 'a') << " ";
    cout << endl;
    
    return 0;
}