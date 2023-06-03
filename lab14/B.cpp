#include "iostream"
#include "string"
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int len = str.length();
    int prefix[len];

    *(prefix + 0) = 0;
    int j = 0;

    for (int i = 1; i < len; i++)
    {
        while (j > 0 and str[i] != str[j])
            j = *(prefix + j - 1);

        if (str[i] == str[j])
            j++;

        else
            j = 0;

        *(prefix + i) = j;
    }

    for (int i = 0; i < len; i++)
        cout << *(prefix + i) << " ";

    return 0;
}