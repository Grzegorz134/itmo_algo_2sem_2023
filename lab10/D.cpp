#include <iostream>
#include "vector"

using namespace std;

void dfs(vector<vector<int>> &graf, bool used[], int v, vector<int> &ans)
{
    *(used + v) = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int to = graf[v][i];
        if (!*(used + to))
            dfs(graf, used, to, ans);
    }
    ans.push_back(v);
}

void topsort(vector<vector<int>> &graf, bool used[], vector<int> &ans, int n)
{
    for (int i = 0; i < n; i++)
        *(used + i) = false;
    ans.clear();

    for (int i = 0; i < n; i++)
    {
        if(!*(used + i))
            dfs(graf, used, i, ans);
    }

    reverse(ans.begin(), ans.end());
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graf[x - 1].push_back(y - 1);
    }

    vector<int> ans(n);
    bool used[n];

    topsort(graf, used, ans, n);

    int rez[n];


    for (int i = 0; i < n; i++)
        *(rez + ans[i]) = i;

    for (int i = 0; i < n; i++)
        cout << *(rez + i) + 1 << " ";

    return 0;
}