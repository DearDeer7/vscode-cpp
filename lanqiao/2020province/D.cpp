/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

bool judge(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    // 1 3 5 7 8 10 12
    int days[13] = {0,31,28,31, 30,31,30, 31,31,30, 31,30,31};
    int w = 6;
    int cnt = 0;
    for(int y = 2000; y <= 2020; ++y) {
        for(int m = 1; m <= 12; ++m) {
            int day = days[m];
            if((m == 2) && judge(y)) day++;
            for(int d = 1; d <= day; d++, w = w % 7 + 1) {
                cnt++;
                if(d == 1 || w == 1) cnt++;
                if(y == 2020 && m == 10 && d == 1) {
                    cout << cnt << endl;
                }
            } 
        }
    }
    
    return 0;
}