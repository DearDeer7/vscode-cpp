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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for(auto eq : equations) {
            if(eq[1] == '=') {
                uf.union_points(eq[0]-'a',eq[3]-'a')
            }
        }

        for(auto eq : equations) {
            if(eq[1] == '!') {
                if(uf.connected(eq[0]-'a', eq[3]-'a'))
                    return false;
            }
        }

        return true;
    }
};