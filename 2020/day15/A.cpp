#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    map<ll, ll> numbers;

    ll turn{ 1 };
    string line;
    while (getline(cin, line))
    {
        numbers.emplace(stoll(line), turn++);
    }

    ll nextNumber{ 0 };

    do
    {
        if (!numbers.contains(nextNumber))
        {
            numbers.emplace(nextNumber, turn++);
            nextNumber = 0;
        }
        else
        {
            ll lastLocaltion{ numbers.at(nextNumber) };
            numbers.at(nextNumber) = turn;
            nextNumber = turn - lastLocaltion;
            ++turn;
        }
    }
    while (turn != 30000000L);

    cout << nextNumber << endl;
}
