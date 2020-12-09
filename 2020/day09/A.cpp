#include <iostream>
#include <string>
#include <list>
#include <unordered_set>

using namespace std;

bool TwoSumA(unordered_set<long long> candidateNumbers, long long target)
{
    for (long long number : candidateNumbers)
    {
        if (candidateNumbers.count(abs(target - number)))
        {
            return true;
        }
    }

    return false;
}

int main2()
{
    int preambleCount{ 0 };

    list<long long> pastNumbersList;
    unordered_set<long long> pastNumbersSet;

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

        long long currentNumber{ stoll(line) };
        if (!TwoSumA(pastNumbersSet, currentNumber))
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
