/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;
const int M = 5007;
int fa[M];

void init(int n) {
    for(int i = 1; i <= n; ++i) fa[i] = i;
}

int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void merge(int i, int j) {
    fa[find(i)] = find(j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int n, m, p;
    cin >> n >> m >> p;

    init(n);
    
    while(m--) {
        int a,b;
        cin >> a >> b;
        merge(a, b);
    }
    while(p--) {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cout << "Yes\n";
        else cout << "No\n";
    }

    
    return 0;
}