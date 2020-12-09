#include <iostream>
#include <string>
#include <list>
#include "Helpers.h"

int main()
{
    int preambleCount{ 0 };

    vector<ll> pastNumbers;
    unordered_set<ll> pastNumbersSet;

    string line;
    size_t elementToRemove{ 0 };
    while (getline(cin, line))
    {
        if (preambleCount < 25)
        {
            pastNumbers.push_back(stoll(line));
            pastNumbersSet.insert(stoll(line));

            ++preambleCount;

            continue;
        }

        ll currentNumber{ stoll(line) };

        pastNumbers.push_back(currentNumber);

        if (!TwoSum(pastNumbersSet, currentNumber))
        {
            break;
        }

        pastNumbersSet.erase(pastNumbers.at(elementToRemove++));
        pastNumbersSet.insert(currentNumber);
    }

    ll lastNumber{ pastNumbers.at(pastNumbers.size() - 1) };
    for (size_t i{ 0 }; i < pastNumbers.size(); ++i)
    {
        ll sum{ pastNumbers.at(i) };
        ll min{ sum };
        ll max{ sum };

        for (size_t j{ i + 1 }; j < pastNumbers.size(); ++j)
        {
            if (pastNumbers.at(j) < min)
            {
                min = pastNumbers.at(j);
            }

            if (pastNumbers.at(j) > max)
            {
                max = pastNumbers.at(j);
            }
            
            sum += pastNumbers.at(j);
            if (sum == lastNumber)
            {
                cout << min + max << endl;

            }
            else if (sum > lastNumber)
            {
                break;
            }
        }
    }

    return 0;
}
