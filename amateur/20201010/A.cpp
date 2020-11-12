/**
 * Created by DearDeer on 2020/10/10
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<char> ops;
    stack<int> vals;

    string s;
    cin >> s;
    int sz = s.size();
    for(int i = 0; i < sz; ++i) {
        char c = s[i];
        if(c == '(') continue;
        if(c <= '9' && c >= '0') vals.push(c - '0');
        else if(c == ')') {
            char tc = ops.top(); ops.pop();
            int a = vals.top(); vals.pop();
            int b = vals.top(); vals.pop();
            
            if(tc == '+') vals.push(a + b);
            else if(tc == '-') vals.push(a - b);
            else if(tc == '*') vals.push(a * b);
            else if(tc == '/') vals.push(a / b);
        }
        else ops.push(c);
    }

    cout << vals.top() << endl;
    
    return 0;
}