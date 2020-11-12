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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
      int a, sum = 0;
      while(n--) {
        cin >> a;
        sum += a;
      }
      cout << sum << '\n';
    }
    return 0;
}