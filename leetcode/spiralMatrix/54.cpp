class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0) return {};
        
        vector<int> ans;
        int cnt = m * n;

        int y = 0, x = -1;
        int right = n, down = m - 1, left = n - 1, up = m - 2;
        while(true) {
            for(int i = 0; i < right; ++i) {
                x++;
                ans.push_back(matrix[y][x]);
                cnt--;
                if(cnt <= 0) return ans;
            }
            for(int i = 0; i < down; ++i) {
                y++;
                ans.push_back(matrix[y][x]);
                cnt--;
                if(cnt <= 0) return ans;
            }
            for(int i = 0; i < left; ++i) {
                x--;
                ans.push_back(matrix[y][x]);
                cnt--;
                if(cnt <= 0) return ans;
            }
            for(int i = 0; i < up; ++i) {
                y--;
                ans.push_back(matrix[y][x]);
                cnt--;
                if(cnt <= 0) return ans;
            }
            right -= 2;
            down -= 2;
            left -= 2;
            up -= 2;

        }

        return ans;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        
        vector<int> ans;
        int cnt = m * n;

        int y = 0, x = 0;
        int right = n - 1, down = m - 1, left = 0, up = 0;
        int dir = 0;
        int total = m * n;
        while(ans.size() < total - 1) {
            if(dir == 0) {
                while(x < right) {
                    ans.push_back(matrix[y][x++]);
                }
                ++up;
            }
            else if(dir == 1) {
                while(y < down) {
                    ans.push_back(matrix[y++][x]);
                }
                --right;
            }
            else if(dir == 2) {
                while(x > left) {
                    ans.push_back(matrix[y][x--]);
                }
                --down;
            }
            else if(dir == 3){
                while(y > up) {
                    ans.push_back(matrix[y--][x]);
                }
                ++left;
            }
            dir = (dir + 1) % 4;
        }

        if(ans.size() != total) ans.push_back(matrix[y][x]);
        return ans;
    }
};

// author : deardeer
// runtime: 0ms
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        
        vector<int> ans;
        int total = m * n;

        // move offsets
        vector<int> dirs{0, 1, 0, -1, 0};
        // border lines
        // right, bottom, left, top
        vector<int> borders{n - 1, m - 1, 0, 1};

        int d = 0; // current direction
        int y = 0, x = 0; // current position
        while(total--) {
            if(d == 0 && x == borders[d]) { // meet right border line
                borders[d]--; // update border line
                d = (d + 1) % 4; // turn to another direction
            }
            else if(d == 1 && y == borders[d]) { // meet bottom border line
                borders[d]--;
                d = (d + 1) % 4;
            }
            else if(d == 2 && x == borders[d]) { // meet left border line
                borders[d]++;
                d = (d + 1) % 4;
            }
            else if(d == 3 && y == borders[d]) { // meet top border line
                borders[d]++;
                d = (d + 1) % 4;
            }

            ans.push_back(matrix[y][x]); // push one element each time
			// move to next position
            y += dirs[d]; 
            x += dirs[d + 1]; 
        }

        return ans;
    }
};