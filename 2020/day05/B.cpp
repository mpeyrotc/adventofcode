
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;

    long long max{ 0 };
    long long min{ INT_MAX };
    long long acc{ 0 };

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

        if (id < min)
        {
            min = id;
        }

        acc += id;
    }

    long long maxSeatIdSum{ (max * (max + 1) / 2) - (min * (min - 1) / 2) };

    cout << maxSeatIdSum - acc << endl;

    return 0;
}