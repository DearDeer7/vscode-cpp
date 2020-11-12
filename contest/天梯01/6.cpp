/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string id;
    int n;
    int cnt = 0;
    vector<int> w{7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    unordered_map<int,char> binds;
    vector<char> M{'1','0', 'X', '9', '8', '7','6', '5', '4', '3', '2'};
    for(int i = 0; i < 11; ++i) binds[i] = M[i];
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> id;
        int sum = 0;
        int j;
        for(j = 0; j <= 11; ++j) {
            if(id[j] <= '9' && id[j] >= '0')
                sum += (id[j] - '0') * w[j];
            else {
                break;
            }
        }
        sum %= 11;
        if(j <= 11 || id.back() != binds[sum]) {
            cout << "wrong:" << j << " " << binds[sum] << endl;
            cout << id << endl;
        }
        else cnt++;
    }

    if(cnt == n) {
        cout << "All passed" << endl;
    }


    
    return 0;
}