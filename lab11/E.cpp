#include "iostream"
#include "vector"
#include "queue"
#define inf 100000000

void dijkstra(std::vector<std::vector<std::pair<int,int>>> &graf, int start, int distance[])
{
    int v, current_distance, to, len;
    std::priority_queue < std::pair <int, int> > queue;

    queue.push( std::make_pair (0,start));

    while (!queue.empty())
    {
        v = queue.top().second;
        current_distance = -queue.top().first;

        queue.pop();

        if (current_distance > *(distance + v))
            continue;

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
    int n, m, weight, start, end, x, y;
    std::cin >> n >> m;
    std::cin >> start >> end;

    std::vector< std::vector <std::pair <int, int>>> graf(n);

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y >> weight;
        graf[x - 1].emplace_back(y - 1, weight);
    }

    int distance[n];
    for (int i = 0; i < n; i++)
        *(distance + i) = inf;
    *(distance + start - 1) = 0;

    dijkstra(graf, start - 1, distance);

    if ( *(distance + end - 1) != inf)
        std::cout << *(distance + end - 1);
    else
        std::cout << "-1";

    return 0;
}