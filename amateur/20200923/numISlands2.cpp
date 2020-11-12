class UF {
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n): count(n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    void union_points(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    int find(int x) {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int get_count() {
        return count;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        UF uf(m * n);
        vector<int> dirs{0, 1, 0, -1, 0};
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    for (int k = 0; k < 4; ++k) {
                        int y = i + dirs[k];
                        int x = j + dirs[k + 1];
                        if(y < 0 || y >= m || x < 0 || x >= n)
                            continue;
                        uf.union_points(i * m + j, y * m + x);
                    }
                }
                else
                    cnt++;
            }
        }
        return uf.get_count() - cnt;
    }
};