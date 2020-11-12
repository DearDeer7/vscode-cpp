// Author: lajila
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f
int a[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>> k;
    int i, j, x, y;
    int maxx = 0;
    for(i = 1; i <= n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int b[maxx + 1];
    while(k--) {
        int sum = 0;
        cin >> x >> y;
        memset(b, 0, sizeof(b));
        for (i = x; i <= y; ++i) {
            b[a[i]]++;

        }
        for (i = 1; i <= maxx; ++i) {
            if(b[i] % 2 == 0 && b[i])
                sum = sum ^ i;

        }
        cout << sum << '\n';
    }
    return 0;
}