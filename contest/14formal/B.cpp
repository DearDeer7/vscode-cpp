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
#include<unordered_map>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    // C, C#, D, D#, E, F, F#, G, G#, A, A# and B.
    unordered_map<string, int> hash;
    hash["C"] = 1;
    hash["C#"] = 2;
    hash["D"] = 3;
    hash["D#"] = 4;
    hash["E"] = 5;
    hash["F"] = 6;
    hash["F#"] = 7;
    hash["G"] = 8;
    hash["G#"] = 9;
    hash["A"] = 10;
    hash["A#"] = 11;
    hash["B"] = 12;
    vector<string> dict{"Major triad", "Minor triad", "Dissonance"};
    while(t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int m = (hash[b] - hash[a] + 12) % 12, n = (hash[c] - hash[b] + 12) % 12;
        if(m == 4 && n == 3) cout << dict[0] << '\n';
        else if (m == 3 && n == 4)
            cout << dict[1] << '\n';
        else
            cout << dict[2] << '\n';
    }
    return 0;
}