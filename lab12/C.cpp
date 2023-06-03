#include "iostream"
#include "vector"
using namespace std;

void make_set(int &v, vector <int > &parent, vector <int > &rang)
{
    parent[v] = v;
    rang[v] = 0;
}

int dsu_get (int &v, vector <int > &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = dsu_get(parent[v], parent);
}

void dsu_unite (int &a, int &b, vector <int > &parent, vector <int > &rang)
{
    a = dsu_get(a, parent);
    b = dsu_get(b, parent);

    if (a != b)
    {
        if (rang[a] < rang[b])
            swap(a, b);

        parent[b] = a;
        if (rang[a] == rang[b])
            ++rang[a];
    }

}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <int > parent(n);
    vector <int > rang(n);
    vector <vector <int >> graf;
    vector <vector <int >> mst1;
    vector <vector <int >> mst2;


    for (int i = 0; i < m; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;

        graf.push_back({weight, x - 1, y - 1});
        mst1.push_back({weight, x - 1, y - 1});
    }

    sort(graf.begin(), graf.end());
    int second, from, to, weight, count, len = 0;

    for (int i = 0; i < n; ++i)
        make_set(i, parent, rang);

    for (int i = 0; i < m; ++i)
    {
        from = graf[i][1];
        to = graf[i][2];
        weight = graf[i][0];
        if (dsu_get(from, parent) != dsu_get(to, parent))
        {
            len += weight;
            mst2.push_back(graf[i]);
            dsu_unite(from,to, parent, rang);
        }
    }

    for (int j = 0; j < m; j++)
    {
        bool tracker = false;
        for (int i = 0; i < mst2.size(); i++)
        {
            if (mst1[j][1] == mst2[i][1] and mst1[j][2] == mst2[i][2] and mst1[j][0] == mst2[i][0])
                tracker = true;
        }

        if (!tracker)
        {
            second = 0;
            count = 0;
            for (int i = 0; i < n; ++i)
                make_set(i, parent, rang);

            from = mst1[j][1];
            to = mst1[j][2];
            weight = mst1[j][0];

            second += weight;
            dsu_unite(from, to, parent, rang);


            for (int i = 0; i < m; ++i)
            {
                if (graf[i][1] != mst1[j][1] or graf[i][2] != mst1[j][2] or graf[i][0] != mst1[j][0])
                {
                    from = graf[i][1];
                    to = graf[i][2];
                    weight = graf[i][0];
                    if (dsu_get(from, parent) != dsu_get(to, parent))
                    {
                        count++;
                        second += weight;

                        if (count >= n)
                            break;
                        dsu_unite(from,to, parent, rang);
                    }
                }
            }

            cout << second << endl;
        }
        else
            cout << len << endl;
    }

    return 0;
}