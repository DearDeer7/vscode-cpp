#include<bits/stdc++.h>
using namespace std;

char grid[1025][1025];

char flip(char c) { return c == 'P' ? 'C' : 'P'; }

void fill() {
    for (int i = 0; i < 10; ++i) {
        int n = 1 << i;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                grid[r][c + n] = grid[r][c];
            } 
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                grid[r + n][c + n] = grid[r][c];
            } 
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                grid[r + n][c] = flip(grid[r][c]);
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin >> t;
    grid[0][0] = 'C';

    fill();

    while(t--) {
        cin >> n;
        n = 1 << n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}