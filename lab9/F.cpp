#include "iostream"
#include "vector"

using namespace std;

int to;

void DFS(vector<vector<int>> &graf, int now, bool color[]){
    for (int i = 0; i < graf[now].size(); i++)
    {
        to = graf[now][i];

        if (!*(color + to))
        {
            *(color + to) = true;
            DFS(graf,to,color);
        }
    }
}

int main(){
    int n, m, x, y; // n - количество вершин, m - количество путей
    short count = 0;
    cin >> n >> m;

    vector<vector <int> > graf(n);


    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graf[x - 1].push_back(y - 1);
        graf[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (graf[i].size() == 1)
            count++;

        if(count > 2)
        {
            cout << "NO";
            return 0;
        }
    }

    bool color[n];

    for (int j = 0; j < n; j++)
        *(color + j) = false;

    *(color + 0) = true;

    DFS(graf,0,color);

    for (int j = 0; j < n; j++)
    {
        if (!*(color + j))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}