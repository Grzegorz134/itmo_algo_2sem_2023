#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graf, int parent[], vector<vector<int>> &cap, int &n)
{
    bool used[n];
    for (int i = 0; i < n; i++)
        *(used + i) = false;

    queue <int> queue;

    queue.push(0);
    *(used + 0) = true;
    *(parent + 0) = -1;

    while (!queue.empty())
    {
        int from = queue.front();
        queue.pop();

        for (int to : graf[from])
        {
            if (!*(used + to) and cap[from][to] > 0)
            {
                *(used + to) = true;
                queue.push(to);
                *(parent + to) = from;
            }
        }
    }
    return *(used + n - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);
    vector<vector<int>> flows(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int x, y, flow;
        cin >> x >> y >> flow;
        graf[x - 1].push_back(y - 1);
        flows[x - 1][y - 1] = flow;
    }

    int parent[n];
    int traffic = 0;

    while ( bfs(graf, parent, flows, n) )
    {
        int past = 101;

        for (int to = n - 1; to > 0; to = *(parent + to))
        {
            int from = *(parent + to);
            past = min(past, flows[from][to]);
        }

        for (int to = n - 1; to > 0; to = *(parent + to))
        {
            int from = *(parent + to);
            flows[to][from] += past;
            flows[from][to] -= past;
        }

        traffic += past;
    }

    cout << traffic;
    return 0;
}