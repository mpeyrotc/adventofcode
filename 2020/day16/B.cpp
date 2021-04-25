#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

vector<int> parseTicketNumbers(string line)
{
    vector<int> result;

    regex numberRegex{ "([0-9]+)" };
    smatch match;
    while (regex_search(line, match, numberRegex))
    {
        result.push_back(stoi(match[1]));
        line = match.suffix();
    }

    return result;
}

bool compliesWithRule(const vector<int>& ticketNumbersInSamePosition, vector<pair<int, int>> ranges)
{
    int numCount{ 0 };

    for (const auto& number : ticketNumbersInSamePosition)
    {
        for (const auto& range : ranges)
        {
            if (number >= range.first && number <= range.second)
            {
                ++numCount;
            }
        }
    }

    return numCount == ticketNumbersInSamePosition.size();
}

bool isValidTicket(const vector<int>& ticketNumbers, const map<string, vector<pair<int, int>>>& ruleMap)
{
    for (const auto& number : ticketNumbers)
    {
        int brokenRuleCount{ 0 };
        for (const auto& rulePair : ruleMap)
        {
            for (const auto& range : rulePair.second)
            {
                if (number < range.first || number > range.second)
                {
                    ++brokenRuleCount;
                }
            }
        }

        if (brokenRuleCount == (ruleMap.size() * 2))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // read rules
    map<string, vector<pair<int, int>>> ruleMap;

    regex ruleRegex{ "([a-z\\s]+): ([0-9]+)-([0-9]+) or ([0-9]+)-([0-9]+)" };
    smatch match;

    string line;
    while (getline(cin, line) && regex_search(line, match, ruleRegex))
    {
        string name{ match[1] };

        auto firstRange{ make_pair(stoi(match[2]), stoi(match[3])) };
        auto secondRange{ make_pair(stoi(match[4]), stoi(match[5])) };
        vector<pair<int, int>> ranges{ firstRange, secondRange };

        ruleMap.emplace(name, ranges);
    }

    // read my ticket
    vector<int> myTicketNumbers;

    getline(cin, line); // ignored
    if (getline(cin, line))
    {
        myTicketNumbers = parseTicketNumbers(line);
    }

    getline(cin, line);
    getline(cin, line);

    // read other ticket numbers
    vector<vector<int>> otherTicketsNumbers;

    while (getline(cin, line))
    {
        vector<int> newTicket = parseTicketNumbers(line);

        if (isValidTicket(newTicket, ruleMap))
        {
            otherTicketsNumbers.push_back(newTicket);
        }
    }

    otherTicketsNumbers.push_back(myTicketNumbers);

    vector<int> departureNumbers;

    while (ruleMap.size() != 0)
    {
        for (size_t i{ 0 }; i < otherTicketsNumbers.at(0).size(); ++i)
        {
            vector<int> sameIndexNumbers;

            for (size_t j{ 0 }; j < otherTicketsNumbers.size(); ++j)
            {
                sameIndexNumbers.push_back(otherTicketsNumbers.at(j).at(i));
            }

            int ruleSuccessCounter{ 0 };
            string ruleName;

            for (const auto& rulePair : ruleMap)
            {
                if (compliesWithRule(sameIndexNumbers, rulePair.second))
                {
                    ++ruleSuccessCounter;
                    ruleName = rulePair.first;
                }
            }

            if (ruleSuccessCounter == 1)
            {
                cout << "Index: " << i << " - " << ruleName << endl;
                ruleMap.erase(ruleName);

                if (ruleName.find("departure") == 0)
                {
                    departureNumbers.push_back(i);
                }
            }
        }
    }

    unsigned long long result{ 1 };
    for (const auto& index : departureNumbers)
    {
        result *= myTicketNumbers.at(index);
    }

    cout << result << endl;

    return 0;
}
