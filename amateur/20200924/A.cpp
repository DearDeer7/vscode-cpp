// Author: DearDeer
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(i == j || j == 0) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n - 1 - i; k++)
            cout << "   ";
        for (int j = 0; j <= i; ++j) {
            cout << "   ";
            printf("%-3d", grid[i][j]);
        }
        cout << '\n';
    }
    system("pause");
    return 0;
}