#include "iostream"
#include "queue"

int main(){
    int n, m, x, y; // n - количество вершин, m - количество путей
    std::cin >> n >> m;

    std::vector< std::vector <int> > graf(n);

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        graf[x - 1].push_back(y - 1);
        graf[y - 1].push_back(x - 1);
    }

    std::cin >> x >> y; // x - шлепа, y - гостиница

    int ranges[n];
    std::queue <int> q;
    int u;
    bool used[n];

    for (int i = 0; i < n; i++)
    {
        *(ranges + i) = -1;
        *(used + i) = false;
    }

    *(ranges + x - 1) = 0;
    q.push(x - 1);
    *(used + x - 1) = true;

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto i: graf[u])
        {
            if (!*(used + i))
            {
                *(used + i) = true;
                q.push(i);
                *(ranges + i) = *(ranges + u) + 1;
            }
        }

    }

    std::cout << *(ranges + y - 1);

    return 0;

}