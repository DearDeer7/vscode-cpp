/**
 * Created by DearDeer on 2020/11/02
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
    string s;
    while(n--) {
        cin >> s;
        int a = s[0] - '0' + s[1] - '0' + s[2] - '0';
        int b = s[3] - '0' + s[4] - '0' + s[5] - '0';
        if(a == b) { 
            cout << "You are lucky!" << endl;
        }
        else cout << "Wish you good luck." << endl;
    }
    
    return 0;
}