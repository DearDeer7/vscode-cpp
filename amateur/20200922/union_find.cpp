// Author: DearDeer
#include<bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    UF uf(4);
    cout << uf.get_count() << endl;
    uf.union_points(1, 2);
    cout << uf.get_count() << endl;
    uf.union_points(3, 2);
    cout << uf.get_count() << endl;
    uf.union_points(1, 0);
    cout << uf.get_count() << endl;
    return 0;
}