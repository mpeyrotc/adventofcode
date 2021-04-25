// day07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <regex>
#include <set>
#include <map>

using namespace std;

map<string, vector<vector<string>>> mapaDeBolsas;

//int caminoShiny(string bolsaMama, vector<vector<int>> caminosAShiny)
//{
//    // caso base
//    if (bolsaMama == "no bolsa")
//    {
//        return 0;
//    }
//
//    bool tieneShiny = false;
//    vector<vector<string>> result;
//
//
//    // por cada bolsita bebe
//    for (auto &bolsaBebe : mapaDeBolsas.at(bolsaMama))
//    {
//        string nombreBolsaBebe = bolsaBebe.at(0/* nombre */);
//        vector<vector<int>> camino;
//
//        if (caminoShiny(nombreBolsaBebe, camino) == 1)
//        {
//            camino.
//            tieneShiny = true;
//        }
//    }
//
//    return tieneShiny ? 1 : 0;
//}
//


















map<string, set<string>> nodeMap;

int visitNodes(string root, set<string>& visited)
{
    if (visited.count(root))
    {
        return 0;
    }

    visited.emplace(root);

    int count{ 0 };
    for (const auto& node : nodeMap.at(root))
    {
        count += visitNodes(node, visited);
    }

    return count + 1;
}

int main2()
{
    string line;
    while (getline(cin, line))
    {
        regex rgx{ "(.*) bags contain (.*)" };
        regex subRgx{ "([0-9]+) ([\\w\\s]+) bags?[\\.,]" };

        if (smatch match; regex_search(line, match, rgx))
        {
            string rootNode{ match[1] };

            if (!nodeMap.contains(rootNode))
            {
                nodeMap.emplace(rootNode, set<string>());
            }

            string possibleBags{ match[2] };
            while (regex_search(possibleBags, match, subRgx))
            {
                string leafNode{ match[2] };

                if (nodeMap.contains(leafNode))
                {
                    nodeMap.at(leafNode).emplace(rootNode);
                }
                else
                {
                    nodeMap.emplace(leafNode, set<string>());
                    nodeMap.at(leafNode).emplace(rootNode);
                }

                possibleBags = match.suffix();
            }
        }
    }

    for (auto a : nodeMap)
    {
        cout << a.first << a.second.size() << endl;
    }

    set<string> visited;

    cout << visitNodes("shiny gold", visited) - 1 << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file