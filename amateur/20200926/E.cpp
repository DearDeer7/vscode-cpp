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

int turn(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else return c - 'a' + 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b) {
        int m = 0, n = 0;
        for (int i = 0; i < a.size(); ++i) m = m * 16 + turn(a[i]);
        for (int i = 0; i < b.size(); ++i) n = n * 16 + turn(a[i]);
        cout << m + n << '\n';
    }
    return 0;
}