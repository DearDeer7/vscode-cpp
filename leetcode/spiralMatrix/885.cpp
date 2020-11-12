class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R * C;
        vector<vector<int>> ans = vector<vector<int>>(total, vector<int>(2,0));
        vector<int> dirs{0, 1, 0, -1, 0};
        vector<int> borders{c0 + 1, r0 + 1, c0 - 1, r0 - 1};

        int d = 0;
        int y = r0, x = c0;

        while(total--) {
            if(d == 0 && x == borders[d]) {
                borders[d]++;
                d = (d + 1) % 4;
            }
            else if(d == 1 && y == borders[d]) {
                borders[d]++;
                d = (d + 1) % 4;
            }
            else if(d == 2 && x == borders[d]) {
                borders[d]--;
                d = (d + 1) % 4;
            }
            else if(d == 3 && y == borders[d]) {
                borders[d]--;
                d = (d + 1) % 4;
            }

            if(y >= 0 && y < r0 && x >= 0 && x < c0) {
                ans.push_back({y,x});
            }
            y += dirs[d];
            x += dirs[d + 1];
        }

        return ans;
    }
};