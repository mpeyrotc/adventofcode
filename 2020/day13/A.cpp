#include <iostream>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>

using namespace std;

void tokenize(std::string const& str, const char delim,
    std::vector<std::string>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

int main()
{
    string line;
    
    getline(cin, line);
    long long startTime{ stoll(line) };

    getline(cin, line);
    vector<string> tokens;
    tokenize(line, ',', tokens);

    /*auto busIds = ranges::ref_view(tokens) |
                  views::filter([](string s) { return s != "x"; }) |
                  views::transform([](string s) { return stoi(s); }) |
                  views::transform([startTime](int id) { return make_pair(id, startTime - (startTime % id) + id); });

    int min{ INT_MAX };
    int id{ 0 };
    for (auto bus : busIds)
    {
        if (bus.second < min)
        {
            min = bus.second;
            id = bus.first;
        }
    }

    cout << (min - startTime) * id << endl;*/

    vector<pair<unsigned long long, int>> ids;

    for (size_t i{ 0 }; i < tokens.size(); ++i)
    {
        if (string token{ tokens.at(i) }; token != "x")
        {
            ids.push_back(make_pair(stoll(token), i));
        }
    }

    
    unsigned long long timeStamp{ ids.at(0).first };
    unsigned long long sum{ 0 };

    do
    {
        sum = 0;
        for (auto& a : ids)
        {
            sum += (timeStamp + a.second) % a.first;
        }

        timeStamp += ids.at(0).first;
    } while (sum != 0);

    cout << timeStamp - ids.at(0).first << endl;

    return 0;
}
