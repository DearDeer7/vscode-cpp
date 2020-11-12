/**
 * Created by DearDeer on 2020/11/02
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> judges = {
        "duo chi yu!",
        "duo chi rou!",
        "wan mei!",
        "ni li hai!",
        "shao chi rou!"
    };  

    int n;
    cin >> n;
    while(n--) {
        int sex, h, w;
        cin >> sex >> h >> w;
        if(sex) {
            if(h > 130) {
                cout << judges[3] << " ";
            }
            else if(h == 130) cout << judges[2] << " ";
            else cout << judges[0] << " ";

            if(w > 27) cout << judges[4] << '\n';
            else if(w == 27) cout << judges[2] << '\n';
            else cout << judges[1] << '\n';
        }
        else {
            if(h > 129) {
                cout << judges[3] << " ";
            }
            else if(h == 129) cout << judges[2] << " ";
            else cout << judges[0] << " ";

            if(w > 25) cout << judges[4] << '\n';
            else if(w == 25) cout << judges[2] << '\n';
            else cout << judges[1] << '\n';
        }
    }
    
    return 0;
}