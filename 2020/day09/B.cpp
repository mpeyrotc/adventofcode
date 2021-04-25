#include <iostream>
#include <string>
#include <list>
#include "Helpers.h"
#include <algorithm>

int main()
{
    int preambleCount{ 0 };

    vector<ll> pastNumbers;
    unordered_set<ll> pastNumbersSet;

    string line;
    size_t elementToRemove{ 0 };
    while (getline(cin, line))
    {
        if (preambleCount < 5)
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
    ll cur{ 0 };
    for (int e = 0, b = 0; e < pastNumbers.size(); e++) {
        cur += pastNumbers[e];
        while (cur > lastNumber) {
            cur -= pastNumbers[b];
            b++;
        }
        if (cur == lastNumber) {
            sort(pastNumbers.begin() + b, pastNumbers.begin() + e);
            cout << pastNumbers[b] + pastNumbers[e] << endl;
            break;
        }
    }

    return 0;
}
