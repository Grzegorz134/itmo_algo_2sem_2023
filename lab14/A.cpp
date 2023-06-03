#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string str;
    string substr;

    cin >> str;
    cin >> substr;

    int n = str.length();
    int m = substr.length();
    vector <int> ans;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (str[i + j] != substr[j])
                break;
        }

        if (j == m)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;

}