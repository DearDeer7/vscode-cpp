class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9, vector<int>(10, 0));
        cols = vector<vector<int>>(9, vector<int>(10, 0));
        boxes = vector<vector<int>>(9, vector<int>(10, 0));
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    rows[i][n] = 1;
                    cols[j][n] = 1;
                    int y = i / 3;
                    int x = j / 3;
                    boxes[y * 3 + x][n] = 1;
                }
            }
        }
        fill(board, 0, 0);
    }
private:
    vector<vector<int>> rows, cols, boxes;
    bool fill(vector<vector<char>>& board, int y, int x) {
        if (y == 9) return true;
        int nx = (x + 1) % 10;
        int ny = nx == 0 ? y + 1 : y;
        if (board[y][x] != '.') return fill(board, ny, nx);
        for(int i = 1; i <= 9; ++i) {
            int by = y / 3;
            int bx = x / 3;
            int bk = by * 3 + bx;
            if (rows[y][i] || cols[x][i] || boxes[bk][i]) continue;
            rows[y][i] = 1;
            cols[x][i] = 1;
            boxes[bk][i] = 1;
            board[y][x] = i + '0';
            if(fill(board, ny, nx)) return true;
            board[y][x] = '.';
            rows[y][i] = 0;
            cols[x][i] = 0;
            boxes[bk][i] = 0;
        }
        return false;
    }
};