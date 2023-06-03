#include "iostream"
#include "cctype"
#include <string>
using namespace std;


int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    string masha, sasha;
    cin >> masha;
    cin >> sasha;

    int check = 0;

    int i = 0, j = 0;

    int lenMasha = 0;
    int lenSasha = 0;

    char ma, sa;


    while (i + 1 < n or j + 1 < m)
    {

        if (lenMasha == 0)
        {
            ma = masha[i];
            i++;

            while (isdigit(masha[i]) and i + 1 < n)
            {
                lenMasha = lenMasha * 10 + masha[i] - '0';
                i++;
            }

        }

        if (lenSasha == 0)
        {
            sa = sasha[j];
            j++;

            while (isdigit(sasha[j]) and j + 1 < m)
            {
                lenSasha = lenSasha * 10 + sasha[j] - '0';
                j++;
            }

        }

        lenMasha--;
        lenSasha--;
        if (ma != sa)
            check += 1;
    }

    if (check < k)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}