/**
 * Created by DearDeer on 2021/04/14/18:51
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

bool isLeap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int gcd(int a,int b) { return b?gcd(b,a%b):a; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0 || j == i) mat[i][j] = 1;
            else mat[i][j] = mat[i - 1][j] + mat[i - 1][j - 1];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}