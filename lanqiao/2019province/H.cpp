/**
 * Created by DearDeer on 2021/04/13/21:48
 */
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}
// int gcd(int a,int b) { return b?gcd(b,a%b):a; }

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int d = INT_MAX;
    for(int i = 1; i < n; ++i ) d = min(d, __gcd(nums[i], nums[i - 1]));
    cout << (nums.back() - nums[0]) / d + 1 << endl;
    return 0;
}