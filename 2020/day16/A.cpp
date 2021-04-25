//#include <iostream>
//#include <regex>
//#include <string>
//#include <vector>
//#include <map>
//#include <numeric>
//
//using namespace std;
//
//vector<int> parseTicketNumbers(string line)
//{
//    vector<int> result;
//
//    regex numberRegex{"([0-9]+)"};
//    smatch match;
//    while (regex_search(line, match, numberRegex))
//    {
//        result.push_back(stoi(match[1]));
//        line = match.suffix();
//    }
//
//    return result;
//}
//
//vector<int> getInvalidNumbers(const vector<int>& ticketNumbers, const map<string, vector<pair<int, int>>>& ruleMap)
//{
//    vector<int> result;
//
//    for (const auto& number : ticketNumbers)
//    {
//        int brokenRuleCount{ 0 };
//        for (const auto& rulePair : ruleMap)
//        {
//            for (const auto& range : rulePair.second)
//            {
//                if (number < range.first || number > range.second)
//                {
//                    ++brokenRuleCount;
//                }
//            }
//        }
//
//        if (brokenRuleCount == (ruleMap.size() * 2))
//        {
//            result.push_back(number);
//        }
//    }
//
//    return result;
//}
//
//int main()
//{
//    // read rules
//    map<string, vector<pair<int, int>>> ruleMap;
//
//    regex ruleRegex{ "([a-z]+): ([0-9]+)-([0-9]+) or ([0-9]+)-([0-9]+)" };
//    smatch match;
//
//    string line;
//    while (getline(cin, line) && regex_search(line, match, ruleRegex))
//    {
//        string name{ match[1] };
//        
//        auto firstRange{ make_pair(stoi(match[2]), stoi(match[3])) };
//        auto secondRange{ make_pair(stoi(match[4]), stoi(match[5])) };
//        vector<pair<int, int>> ranges{ firstRange, secondRange };
//
//        ruleMap.emplace(name, ranges);
//    }
//
//    // read my ticket
//    vector<int> myTicketNumbers;
//    
//    getline(cin, line); // ignored
//    if (getline(cin, line))
//    {
//        myTicketNumbers = parseTicketNumbers(line);
//    }
//
//    getline(cin, line);
//    getline(cin, line);
//
//    // read other ticket numbers
//    vector<vector<int>> otherTicketsNumbers;
//
//    while (getline(cin, line))
//    {
//        otherTicketsNumbers.push_back(parseTicketNumbers(line));
//    }
//
//    // check which tickets are invalid.
//    long long result{ 0 };
//    for (const auto& ticketNumbers : otherTicketsNumbers)
//    {
//        vector<int> invalidNumbers = getInvalidNumbers(ticketNumbers, ruleMap);
//        result += accumulate(begin(invalidNumbers), end(invalidNumbers), 0);
//    }
//
//    cout << result << endl;
//
//    return 0;
//}
