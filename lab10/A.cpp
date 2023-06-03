#include <iostream>
#include "vector"

using namespace std;

void dfs(vector<vector<int>> &graf, int used[], int v, int kp)
{
    *(used + v) = kp;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int to = graf[v][i];
        if (!*(used + to))
            dfs(graf, used, to, kp);
    }
}

int main()
{
    int n, m, x, y, kp = 1;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graf[x - 1].push_back(y - 1);
        graf[y - 1].push_back(x - 1);
    }

    bool traps[n];
    int used[n];

    for (int i = 0; i < n; i++)
    {
        cin >> *(traps + i);
        *(used + i) = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!*(used + i))
        {
            dfs(graf, used, i, kp);
            kp++;
        }
    }

    bool trapKP[kp];
    for (int i = 0; i < kp - 1; i++)
        *(trapKP + i) = false;

    for (int i = 0; i < n; i++)
    {
        if (*(traps + i))
            *(trapKP + *(used + i) - 1) = true;
    }

    cout << kp - 1 << endl;

    for (int i = 0; i < n; i++)
        cout << *(used + i) << " ";

    cout << endl;

    for(int i = 0; i < kp - 1; i++)
        cout << *(trapKP + i) << " ";

    return 0;
}