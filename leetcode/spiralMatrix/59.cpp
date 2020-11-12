class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n, 0));
        
        vector<int> dirs{0, 1, 0, -1, 0};
        vector<int> borders{n - 1, n - 1, 0, 1};

        int d = 0, y = 0, x = 0, i = 0;

        int total = n * n;
        while(i++ <= total) {
            if(d == 0 && x == borders[d]) {
                borders[d]--;
                d = (d + 1) % 4;
            }
            else if(d == 1 && y == borders[d]) {
                borders[d]--;
                d = (d + 1) % 4;
            }
            else i(d == 2 && x == borders[d]) {
                borders[d]++;
                d = (d + 1) % 4;
            }
            else if(d == 3 && y == borders[d]) {
                borders[d]++;
                d = (d + 1) % 4;
            }

            ans[y][x] = i;
            y += dirs[d];
            x += dirs[d + 1];
        }

        return ans;
    }
};