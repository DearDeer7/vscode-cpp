/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;
int vv[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int cnt = 1;
    for(int i = 0; i < 40; ++i) {
        if(i % 2) {
            for(int y = 0, x = i; x >= 0; y++, x--) {
                vv[y][x] = cnt++;
            }
        }
        else {
            for(int y = i, x = 0; y >= 0; y--, x++) {
                vv[y][x] = cnt++;
            } 
        }
    }
    cout << vv[1][1] << endl;
    cout << vv[19][19];
    
    return 0;
}