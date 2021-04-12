/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

#define DEER 1
#define endl '\n'
typedef long long ll;

bool isPalindrome(string& s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

bool isAB(string& s) {
    char ch[2] = {s[0], s[1]};
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j] || s[i] != ch[i % 2] || s[j] != ch[i % 2])
            return false;
        i++, j--; 
    }
    return true;
}

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

string join(int y, int m, int d) {
    string t = to_string(y);
    t += m / 10 + '0';
    t += m % 10 + '0';
    t += d / 10 + '0';
    t += d % 10 + '0';
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    string s;
    cin >> s;
    int flag = 0;
    if(isPalindrome(s)) {
        s[3] = s[3] + 1;
    }

    int days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

    int y = stoi(s.substr(0, 4)) - 1;
    while(++y <= 8999) {
        // cout << y << endl;
        // 1234 43 21
        int m = y % 100 / 10 + y % 10 * 10;
        int d = y % 1000 / 100 * 10 + y / 1000;
        if(m > 12) continue;
        int dayM = days[m] + (m == 2 ? isLeap(y) : 0);
        if(d > dayM) continue;
        string t = join(y, m, d);
        if(!flag) {
            cout << t << endl;
            flag = 1;
        }
        if(isAB(t)) {
            cout << t << endl;
            return 0;
        }
    }
    return 0;
}