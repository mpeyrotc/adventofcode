#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main2()
{
    vector<string> instructions;
    vector<int> args;
    vector<bool> executed;
    vector<long> ips;

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
            cout << instructions.at(ip) << " " << args.at(ip) << " ---- " << ip << endl;
            break;
        }

        ips.push_back(ip);
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

    vector<long> candidates;
    for (int i = ips.size() - 2; i >= 0; i--)
    {
        if (instructions.at(ips.at(i)) == "jmp" && !executed.at(ips.at(i) + 1))
        {
            cout << instructions.at(ips.at(i)) << " " << args.at(ips.at(i)) << " ----- " << ips.at(i) << endl;
            candidates.push_back(ips.at(i));
        }
        else if (instructions.at(ips.at(i)) == "nop" && !executed.at(ips.at(i) + args.at(ips.at(i))))
        {
            cout << instructions.at(ips.at(i)) << " " << args.at(ips.at(i)) << " ----- " << ips.at(i) << endl;
            candidates.push_back(ips.at(i));
        }
    }

    
    for (long c : candidates)
    {
        executed.clear();
        for (string s : instructions)
        {
            executed.push_back(false);
        }

        while (true)
        {
            if (executed.at(ip))
            {
                cout << instructions.at(ip) << " " << args.at(ip) << " ---- " << ip << endl;
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
                if (ip == c)
                {
                    executed.at(ip) = true;
                    ip += args.at(ip);
                }
                else
                {
                    executed.at(ip) = true;
                    ++ip;
                }

                
            }
            else
            {
                if (ip == c)
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
        }
    }

    return 0;
}
