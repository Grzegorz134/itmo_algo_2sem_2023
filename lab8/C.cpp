#include "iostream"
#include "string"
#include "cmath"

using namespace std;

int error(string str)
{
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
            count ^= i + 1;
    }

    return count;
}

int main(){
    short t;
    cin >> t;

    string hamming;

    for (short j = 0; j < t; j++)
    {
        cin >> hamming;

        if (error(hamming))
        {
            hamming[error(hamming) - 1] ^= '0' ^ '1';
        }

        short decrease = 0, len = hamming.length();

        for (short i = 0; i < len; i++)
        {
            if (i - decrease >= pow(2,decrease) - 1 - decrease)
            {
                hamming.erase(i - decrease, 1);
                decrease++;
            }
        }

        cout << hamming << endl;
    }

    return 0;
}