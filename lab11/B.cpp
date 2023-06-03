#include "iostream"
#define INF 1000000000

int main()
{
    int m, n, x,y, weight, past = 0;
    std::cin >> n >> m;
    int graf[n][n];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                *(*(graf + i) + j) = 0;
            else
                *(*(graf + i) + j) = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y >> weight;
        *(*(graf + x - 1) + y - 1) = weight;
        *(*(graf + y - 1) + x - 1) = weight;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(*(graf + i) + j) = std::min( *(*(graf + i) + j), *(*(graf + i) + k) + *(*(graf + k) + j) );
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(graf + i) + j) != INF)
                past = std::max(past, *(*(graf + i) + j));
        }
    }

    std::cout << past << std::endl;

    return 0;
}