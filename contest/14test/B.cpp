// Author: DearDeer
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f
int grid[200007][200007];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    memset(grid, INT_MAX, sizeof(grid));
    cin >> n >> m >> q;
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        grid[a][b] = c;
        grid[b][a] = c;
    }
    while(q--) {
        int bro;
        cin >> bro;
        
    }

    return 0;
}