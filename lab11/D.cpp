#include "iostream"
#include "vector"
#include "queue"
#define inf 100000000

void dijkstra(std::vector<std::vector<std::pair<int,int>>> &graf, int start, int distance[])
{
    int v, to, len;
    std::priority_queue < std::pair <int, int> > queue;

    queue.push( std::make_pair (0,start));

    while (!queue.empty())
    {
        v = queue.top().second;

        queue.pop();

        for (int i = 0; i < graf[v].size(); i++)
        {
            to = graf[v][i].first, len = graf[v][i].second;

            if ( *(distance + v) + len < *(distance + to) )
            {
                *(distance + to) = *(distance + v) + len;
                queue.push ( std::make_pair(-*(distance + to), to));
            }
        }
    }
}

int main(){
    int n, m, weight, request, start, end, x, y;
    std::cin >> n >> m >> request >> start;

    std::vector< std::vector <std::pair <int, int>>> graf(n);

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y >> weight;
        graf[x - 1].emplace_back(y - 1, weight);
        graf[y - 1].emplace_back(x - 1, weight);
    }

    int distance[n];
    for (int i = 0; i < n; i++)
        *(distance + i) = inf;
    *(distance + start - 1) = 0;

    dijkstra(graf, start - 1, distance);

    for (int i = 0; i < request; i++)
    {
        std::cin >> end;

        if ( *(distance + end - 1) == inf)
            std::cout << "-1" << std::endl;
        else
            std::cout << *(distance + end - 1) << std::endl;
    }

    return 0;
}