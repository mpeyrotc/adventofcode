#include <iostream>
#include <string>
#include <list>
#include "Helpers.h"

bool TwoSum(unordered_set<ll> candidateNumbers, ll target)
{
    for (ll number : candidateNumbers)
    {
        if (ll other{ abs(target - number) }; candidateNumbers.count(other) && other != number)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int preambleCount{ 0 };

    list<ll> pastNumbersList;
    unordered_set<ll> pastNumbersSet;

    string line;
    while (getline(cin, line))
    {
        if (preambleCount < 25)
        {
            pastNumbersList.push_back(stoll(line));
            pastNumbersSet.insert(stoll(line));

            ++preambleCount;

            continue;
        }

        ll currentNumber{ stoll(line) };
        if (!TwoSum(pastNumbersSet, currentNumber))
        {
            cout << currentNumber << endl;
        }

        pastNumbersSet.erase(pastNumbersList.front());
        pastNumbersSet.insert(currentNumber);

        pastNumbersList.pop_front();
        pastNumbersList.push_back(currentNumber);
    }

    return 0;
}
