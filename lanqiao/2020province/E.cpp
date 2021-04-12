/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

/**
 * union find
 */
int fa[1000];
void init(int n){
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}
int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
int union(int i, int j) {
    fa[find(i)] = find(j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    
    
    return 0;
}