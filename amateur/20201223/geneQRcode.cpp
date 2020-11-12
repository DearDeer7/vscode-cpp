/**
 * Created by DearDeer on 2020/12/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums{1,2,3};

    vector<vector<int>> pers;

    do{
        pers.push_back(nums);
    }while(next_permutation(nums.begin(), nums.end()));

    int cnt = 0;

    for(auto per : pers) {
        for(auto per2: pers) {
            for(int i : per2) cout << i;
            cout << "+";
            for(int j : per) cout << j;
            cout << endl;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}