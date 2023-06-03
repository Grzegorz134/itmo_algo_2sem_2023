#include "iostream"
#include "vector"

void bellman_ford(std::vector <std::vector <int>> &graf, int &n, int &m, int &lenCycle)
{
    std::vector <int> distance(n, INT_MAX), parent(n, -1);

    distance[0] = 0;
    int x;

    for (int i = 0; i < n; i++)
    {
        x = -1;
        bool tracker = false;
        for (int j = 0; j < m; j++)
        {
            if (distance[graf[j][0]] < INT_MAX)
            {
                if ( distance[graf[j][1]] > distance[graf[j][0]] + graf[j][2])
                {
                    distance[graf[j][1]] = std::max(INT_MIN, distance[graf[j][0]] + graf[j][2]);
                    parent[graf[j][1]] = graf[j][0];
                    x = graf[j][1];

                    tracker = true;
                }
            }
        }

        if (!tracker)
            break;
    }

    std::vector <int> path;

    if (x == -1)
        std::cout << "YES" << std::endl;
    else
    {
        int y = x;

        for (int i = 0; i < n; i++)
            y = parent[y];

        for (int i = y; i != y or path.empty(); i = parent[i])
            path.push_back(i);


        if (path.size() < lenCycle or path.empty())
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}

int main(){

    int countGraf, lenCycle;
    std::vector <std::vector <int>> graf;
    std::cin >> countGraf >> lenCycle;

    for (int k = 0; k < countGraf; k++)
    {
        int n, m;
        std::cin >> n >> m;

        graf.clear();

        for (int i = 0; i < m; i++)
        {
            int x, y, weight;
            std::cin >> x >> y >> weight;
            graf.push_back({x - 1, y - 1, weight});
        }

        bellman_ford(graf, n, m, lenCycle);
    }
    return 0;
}