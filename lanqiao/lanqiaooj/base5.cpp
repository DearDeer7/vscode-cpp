/**
 * Created by DearDeer on 2021/04/14/19:16
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n < 10) {
        cout << n;
        return 0;
    }
    vector<int> nums;
    while(n) {
        nums.push_back(n % 16);
        n /= 16;
    }
    for(int i = nums.size() - 1; i >= 0; --i) {
        int e = nums[i];
        if(e > 9) cout << char(e - 10 + 'A');
        else cout << e;
    }
    
    return 0;
}