#include "iostream"
#include "vector"

using namespace std;

bool kun(int v, bool used[], vector <vector <int> > &graf, int mt[])
{
    if (*(used + v))
        return false;

    *(used + v) = true;

    for (int i = 0; i < graf[v].size(); ++i)
    {
        int to = graf[v][i];

        if (*(mt + to) == -1 or kun(mt[to], used, graf,mt))
        {
            *(mt + to) = v;
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    int cross[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            *(*(cross + i) + j) = false;
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        *(*(cross + x - 1) + y - 1) = true;
    }

    vector <vector <int> > graf(n*m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!*(*(cross + i) + j))
            {
                if (j - 1 >= 0 and !(*(*(cross + i) + j - 1)))
                    graf[i * m + j].push_back((i * m) + j - 1);

                if (j + 1 < m and !(*(*(cross + i) + j + 1)))
                    graf[i * m + j].push_back((i * m) + j + 1);

                if (i - 1 >= 0 and !(*(*(cross + i - 1) + j)))
                    graf[i * m + j].push_back((i * m) + j - m);

                if (i + 1 < n and !(*(*(cross + i + 1) + j)))
                    graf[i * m + j].push_back((i * m) + j + m);

            }
        }
    }

    bool used[n*m];
    int mt[n*m];

    for (int i = 0; i < m*n; i++)
    {
        *(used + i) = false;
        *(mt + i) = -1;
    }

    for (int v = 0; v < n*m; ++v)
    {
        for (int i = 0; i < n*m; ++i)
            *(used + i) = false;

        kun(v, used, graf, mt);
    }

    int count = 0;
    for (int i = 0; i < n*m; ++i)
    {
        if ( *(mt + i) != -1)
            count++;
    }

    cout << count;
    return 0;
}