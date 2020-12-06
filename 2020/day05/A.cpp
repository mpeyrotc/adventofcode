
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;

    int max{ 0 };
    while (getline(cin, line))
    {
        long long id{ 0 };
        for (size_t shiftValue{ line.size() - 1 }; const char c : line)
        {
            if (c == 'B' || c == 'R')
            {
                id |= (static_cast<long long>(1) << shiftValue);
            }

            --shiftValue;
        }

        if (id > max)
        {
            max = id;
        }
    }

    cout << max << endl;

    return 0;
}