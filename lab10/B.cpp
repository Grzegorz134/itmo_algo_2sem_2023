#include <iostream>
#include "vector"

using namespace std;

void dfs(vector<vector<int>> &graf, bool used[], int v)
{
    *(used + v) = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int to = graf[v][i];
        if (!*(used + to))
            dfs(graf, used, to);
    }
}

void clearUsed(bool used[], int n)
{
    for (int i = 0; i < n; i++)
        *(used + i) = false;
}

int main()
{
    int n, m, x, y, q;
    cin >> n >> m >> q;

    vector<vector<int>> graf(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graf[x - 1].push_back(y - 1);
        graf[y - 1].push_back(x - 1);
    }

    string oper;
    bool used[n];

    for (int i = 0; i < q; i++)
    {
        clearUsed(used,n);
        cin >> oper >> x >> y;

        if (oper == "?")
        {
            dfs(graf, used, x - 1);

            if (*(used + x - 1) and *(used + y - 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        if (oper == "-")
        {
            erase(graf[x - 1], y - 1);
            erase(graf[y - 1], x - 1);
        }
    }
    return 0;
}