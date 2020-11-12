#include <cstring>
include<iostream> using namespace std;
const int MAXN = 1e3 + 7;
int T, n, m, cnt, fa[MAXN], vis[MAXN];
int Find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[×] = Find(fa[×]);
}
void Union(int x, int y) { fa[y] = x; }
int main(
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int x, y, i = 1; i <= m; i++)
        {
            cin >> x >> y;
            int fx = Find(x), fy = Find(y);
            if(fx != fy)
                Union(fx, fy);
        }
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (int i = 1; i <= n; i++)
            int fx = Find(i);
        if (!vis[fx])
            cnt++, vis[fx] = 1;
        cout<< cnt <<endl;
    }
    return o;
}

