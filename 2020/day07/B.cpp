#include <iostream>
#include <string>
#include <regex>
#include <set>
#include <map>

using namespace std;

map<string, vector<string>> nodeMap;
map<string, vector<int>> nodeValMap;

long long visitNodes2(string root, set<string>& visited)
{
    visited.emplace(root);

    long long count{ 0 };
    for (size_t i{ 0 }; i < nodeValMap.at(root).size(); ++i)
    {
        string name{ nodeMap.at(root).at(i) };
        long long first = nodeValMap.at(root).at(i);
        long long second = visitNodes2(name, visited);
        count += first * second;
    }

    return count + 1;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        regex rgx{ "(.*) bags contain (.*)" };
        regex subRgx{ "([0-9]+) ([\\w\\s]+) bags?[\\.,]" };

        if (smatch match; regex_search(line, match, rgx))
        {
            string rootNode{ match[1] };


            nodeMap.emplace(rootNode, vector<string>());
            nodeValMap.emplace(rootNode, vector<int>{});


            string possibleBags{ match[2] };
            while (regex_search(possibleBags, match, subRgx))
            {
                string leafNode{ match[2] };


                nodeMap.at(rootNode).push_back(leafNode);
 
                int val{ stoi(match[1]) };
                nodeValMap.at(rootNode).push_back(val);


                possibleBags = match.suffix();
            }
        }
    }

    set<string> visited;

    cout << visitNodes2("shiny gold", visited) - 1 << endl;

    return 0;
}