#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> instructions;
    vector<int> args;
    vector<bool> executed{};

    regex rgx{ string("([a-z]{3})\\s([\\+\\-][0-9]+)") };

    string line;
    while (getline(cin, line))
    {
        smatch match;
        if (regex_search(line, match, rgx))
        {
            string instruction{ match[1] };
            int arg{ stoi(match[2]) };

            instructions.push_back(instruction);
            args.push_back(arg);
            executed.push_back(false);
        }
    }

    long acc{ 0 };
    long ip{ 0 };
    while (true)
    {
        if (executed.at(ip))
        {
            cout << acc << endl;
            break;
        }

        if (instructions.at(ip) == "acc")
        {
            acc += args.at(ip);
            executed.at(ip) = true;
            ++ip;
        }
        else if (instructions.at(ip) == "nop")
        {
            executed.at(ip) = true;
            ++ip;
        }
        else
        {
            executed.at(ip) = true;
            ip += args.at(ip);
        }
    }

    return 0;
}
