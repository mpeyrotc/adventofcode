#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <numeric>

using namespace std;

typedef long long ll;

string parseMaskString(ll mask)
{
    string result{ "000000000000000000000000000000000000" };

    ll m{ 1 };

    size_t shiftValue{ result.size() - 1 };

    while (mask != 0)
    {
        if ((mask & m) != 0)
        {
            result.at(shiftValue) = '1';
        }

        mask = mask >> 1;
        --shiftValue;
    }

    return result;
}

ll parseMask(string mask)
{
    ll result{ 0 };
    for (size_t shiftValue{ mask.size() - 1 }, index{ 0 }; const char c : mask)
    {
        char maskBit{ mask.at(index) };

        if (maskBit == '1')
        {
            result |= (static_cast<ll>(1LL) << shiftValue);
        }

        --shiftValue;
        ++index;
    }

    return result;
}

int main()
{
    regex maskRegex("mask = ([X10]{36})");
    regex instructionRegex("mem\\[([0-9]+)\\] = ([0-9]+)");

    map<string, ll> memory;

    string line;
    string maskString;
    while (getline(cin, line))
    {
        if (smatch match; regex_search(line, match, maskRegex))
        {
            maskString = match[1];
        }
        else if (regex_search(line, match, instructionRegex))
        {
            ll memAddress{ stoll(match[1]) };
            ll value{ stoll(match[2]) };

            vector<string> candidateAddresses{ parseMaskString(memAddress) };
            for (size_t i{ 0 }; i < maskString.size(); ++i)
            {
                if (maskString.at(i) == 'X')
                {
                    for (size_t j{ 0 }; j < candidateAddresses.size(); ++j)
                    {
                        candidateAddresses.at(j).at(i) = '1';
                    }
                    
                    size_t jSize{ candidateAddresses.size() };
                    for (size_t j{ 0 }; j < jSize; ++j)
                    {
                        string newAddress = candidateAddresses.at(j);
                        newAddress.at(i) = '0';
                        candidateAddresses.push_back(newAddress);
                    }
                }
                else if (maskString.at(i) == '1')
                {
                    for (size_t j{ 0 }; j < candidateAddresses.size(); ++j)
                    {
                        candidateAddresses.at(j).at(i) = '1';
                    }
                }
            }

            for (auto candidateAddress : candidateAddresses)
            {
                if (memory.contains(candidateAddress))
                {
                    memory.at(candidateAddress) = value;
                }
                else
                {
                    memory.emplace(candidateAddress, value);
                }
            }
        }
    }

    ll total{ 0 };
    for (const auto& p : memory)
    {
        total += p.second;
    }

    cout << total << endl;

    return 0;
}