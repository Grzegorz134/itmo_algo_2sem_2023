#include "iostream"
#include "vector"

using namespace std;

bool DFS(vector<vector<int>> &graf, int now, int parent, short color[])
{
    *(color + now) = 1;
    for (auto i: graf[now])
    {
        if(*(color + i) == 0)
        {
            if (DFS(graf,i,now,color))
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }
    return false;
}

int main(){
    int n, m, x, y; // n - количество вершин, m - количество путей
    cin >> n >> m;

    bool tracker = false;

    vector<vector <int> > graf(n);
    short color[n];

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graf[x - 1].push_back(y - 1);
        graf[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++)
        *(color + i) = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(color + i) == 0)
        {
            if (DFS(graf,i,-1,color))
            {
                tracker = true;
                break;
            }
        }
    }

    if (tracker)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}