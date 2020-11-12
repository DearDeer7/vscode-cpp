/**
 * Created by DearDeer on 2021/01/04
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums{1,3,5,7,9,2,4,6};

    sort(nums.begin(), nums.end(), [] (int a, int b) { return a < b;});

    for(int a : nums) cout << a << ' ';
    cout << endl;

    [] () {
        cout << "hello" << endl;
    }();
    
    
    return 0;
}