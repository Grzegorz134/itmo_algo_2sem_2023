#include "iostream"
#include "string"
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n,m, rez = 0;
    cin >> n >> m;

    string str;
    cin >> str;

    for (int k = 0; k < m; k++)
    {
        int first, second, len, count = 0;
        cin >> first >> second >> len;

        int i = first - 1, j = second - 1;

        while (i != first + len - 1 and j != second + len - 1)
        {
            if (str[i++] == str[j++])
                count++;
        }

        if (count == len)
            rez++;
    }

    cout << rez;

    return 0;
}