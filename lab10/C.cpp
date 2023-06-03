#include <iostream>
#include "vector"

using namespace std;

void dfs(vector<vector<int>> &graf, bool (&used)[], int v, int finish)
{
    *(used + v) = true;

    if (!*(used + finish))
    {
        for (int i = 0; i < graf[v].size(); i++)
        {
            int to = graf[v][i];
            if (!*(used + to))
                dfs(graf, used, to, finish);
            if (*(used + finish))
                break;
        }
    }
}

void clearUsed(bool forward[], bool back[], int n)
{
    for (int i = 0; i < n; i++)
    {
        *(forward + i) = false;
        *(back + i) = false;
    }
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
    }

    bool usedForward[n];
    bool usedBack[n];

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        clearUsed(usedForward, usedBack,n);

        dfs(graf, usedForward, x - 1, y - 1);

        if (*(usedForward + x - 1) and *(usedForward + y - 1))
        {
            dfs(graf, usedBack, y - 1, x - 1);

            if (*(usedBack + x - 1) and *(usedBack + y - 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}