/**
 * Created by DearDeer on 2020/11/02
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

bool isPrime(int n) {
    if(n < 2) return false;
    int N = sqrt(n);
    for(int i = 2; i <= N; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

bool valid(int n, set<int>& s) {
    // vector<int> digits;
    if(n == 1) {
        s.insert(n);
        return true;
    }
    int new_n = 0;
    while(n) {
        new_n += (n % 10) * (n % 10);
        n /= 10;
    }
    if(s.count(new_n)) {
        // s.clear();
        return false;
    }
    s.insert(new_n);
    return valid(new_n,s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b;
    cin >> a >> b;

    vector<pair<int,int>> ans;

    for(int i = a; i <= b; ++i) {
        set<int> s;
        if(valid(i, s)) {
            int w = s.size() - 1;
            ans.push_back({i, w * (isPrime(i) ? 1 : 2)});
        }
    }
    sort(ans.begin(), ans.end(), 
        [=] (pair<int,int> a, pair<int,int> b) { 
            return a.first < b.first;
        }
    );

    if(ans.size() == 0) {
        cout << "SAD";
    }
    else {
        for(auto i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
    
    return 0;
}