#include "iostream"
#include "cmath"

int main()
{
    int m, n, x,y, weight, q;
    std::cin >> n >> m >> q;
    int graf[n][n];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                *(*(graf + i) + j) = 0;
            else
                *(*(graf + i) + j) = 1000000000;
        }
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y >> weight;
        *(*(graf + x - 1) + y - 1) = weight;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(i - k) <= q and abs(j - k) <= q)
                    *(*(graf + i) + j) = std::min( *(*(graf + i) + j), *(*(graf + i) + k) + *(*(graf + k) + j) );
            }
        }
    }

    int request;
    std::cin >> request;

    for (int i = 0; i < request; i++)
    {
        std::cin >> x >> y;
        if ( *(*(graf + x - 1) + y - 1) == 1000000000)
            std::cout << "-1" << std::endl;
        else
            std::cout << *(*(graf + x - 1) + y - 1) << std::endl;
    }

    return 0;
}