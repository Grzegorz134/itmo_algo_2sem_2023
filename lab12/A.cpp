#include "iostream"
#include "vector"
using namespace std;

void make_set(long &v, vector <long> &parent, vector <long> &rang)
{
    parent[v] = v;
    rang[v] = 0;
}

long dsu_get (long &v, vector <long> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = dsu_get(parent[v], parent);
}

void dsu_unite (long &a, long &b, vector <long> &parent, vector <long> &rang)
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n, m;
    cin >> n >> m;

    vector <long> parent(n);
    vector <long> rang(n);
    vector <vector <long>> graf;

    for (long i = 0; i < m; i++)
    {
        long x, y, weight;
        cin >> x >> y >> weight;

        graf.push_back({weight, x - 1, y - 1});
    }

    sort(graf.begin(), graf.end());

    for (long i = 0; i < n; ++i)
        make_set(i, parent, rang);

    long a, b, len = 0, l, count = 0;

    for (long i = 0; i < m; ++i)
    {
        a = graf[i][1];
        b = graf[i][2];
        l = graf[i][0];
        if (dsu_get(a, parent) != dsu_get(b, parent))
        {
            count++;
            len += l;

            if (count >= n)
                break;

            dsu_unite(a,b, parent, rang);

        }
    }

    cout << len;
    return 0;
}