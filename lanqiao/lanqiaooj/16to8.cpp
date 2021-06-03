/**
 * Created by DearDeer on 2021/04/14/19:56
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

string h2b[] = {
    "0000"
    ,"0001"
    ,"0010"
    ,"0011"
    ,"0100"
    ,"0101"
    ,"0110"
    ,"0111"
    ,"1000"
    ,"1001"
    ,"1010"
    ,"1011"
    ,"1100"
    ,"1101"
    ,"1110"
    ,"1111"};
// unordered_map<string, int> o2b;

void solve(string& s) {
    const int n = s.size();
    string bin;
    for(int i = 0; i < n; ++i) {
        int d;
        if(isdigit(s[i])) d = s[i] - '0';
        else d = s[i] - 'A' + 10;
        bin += h2b[d];
    }
    // cout << bin << endl;
    int sz = bin.size();
    if(sz % 3 == 1) bin = "00" + bin;
    else if(sz % 3 == 2) bin = "0" + bin;
    sz = bin.size();
    for(int i = 0; i < sz; i += 3) {
        string ts = bin.substr(i, 3);
        if(ts == "000") cout << 0;
        else if(ts == "001") cout << 1;
        else if(ts == "010") cout << 2;
        else if(ts == "011") cout << 3;
        else if(ts == "100") cout << 4;
        else if(ts == "101") cout << 5;
        else if(ts == "110") cout << 6;
        else if(ts == "111") cout << 7;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        solve(s);
    }
    
    return 0;
}