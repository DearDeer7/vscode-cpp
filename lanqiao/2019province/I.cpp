/**
 * Created by DearDeer on 2021/04/13/22:01
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int p = n + m + 1;
    vector<int> nums(p);
    for(int i = 0; i < p; ++i) cin >> nums[i];
    sort(begin(nums), end(nums), [] (int a, int b) {return a > b;});
    for(int i = 1; i < p; ++i) {
        int a = nums[i - 1], b = nums[i];
        // cout << a << "," << b << endl;
        if(n > 0) {
            nums[i] = a + b;
            n--;
        }
        else if(m > 0) {
            nums[i] = a - b;
            m--;
        }
    }
    cout << nums.back() << endl;
    
    return 0;
}