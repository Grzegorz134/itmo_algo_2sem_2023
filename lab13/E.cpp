#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, count = 0;
    cin >> n;

    int hash[n], heights[20000001];

    for (int i = 0; i < n; i++)
        cin >> *(hash + i);

    for (int i = 0; i < 20000001; i++)
        *(heights + i) = 0;

    for (int i = 0; i < n; i++)
    {
        int tall = *(hash + i);
        int res = i - tall + 10000000;

        if (res >= 0 and res <= 20000001)
            count += *(heights + res);

        *(heights + res) += 1;
    }

    cout << count;

    return 0;
}