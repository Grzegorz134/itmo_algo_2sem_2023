#include <iostream>
#include <vector>
#include <list>
using namespace std;
int n;
template<typename type>
class HashSet {
private:
    vector<list<type>> table;
    type capacity;

public:
    HashSet(type capacity = n) : capacity(capacity)
    {
        table.resize(capacity);
    }

    type hash(const type& element) const
    {
        return element % capacity;
    }

    void insert(const type& element)
    {
        list <type>& bucket = table[hash(element)];

        if (find(bucket.begin(), bucket.end(), element) != bucket.end())
            return;

        bucket.push_back(element);
    }

    bool operator==(const HashSet& other) const
    {
        for (int i = 0; i < capacity; i++)
        {
            const list<type>& bucket = table[i];
            const list<type>& otherBucket = other.table[i];

            for (const type& element : bucket)
            {
                if (find(otherBucket.begin(), otherBucket.end(), element) == otherBucket.end())
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    HashSet <int> first;
    HashSet <int> second;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        first.insert(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        second.insert(x);
    }

    if (first == second)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}