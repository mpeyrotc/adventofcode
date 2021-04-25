//#include <iostream>
//#include <string>
//#include <regex>
//#include <map>
//#include <numeric>
//
//using namespace std;
//
//typedef long long ll;
//
//ll parseMask(string mask, bool isMask0)
//{
//    ll result{ 0 };
//    for (size_t shiftValue{ mask.size() - 1 }, index{ 0 }; const char c : mask)
//    {
//        char maskBit{ mask.at(index) };
//
//        if (maskBit == '1' && !isMask0)
//        {
//            result |= (static_cast<ll>(1LL) << shiftValue);
//        }
//        else if (maskBit == '0' && isMask0)
//        {
//            result |= (static_cast<ll>(1LL) << shiftValue);
//        }
//
//        --shiftValue;
//        ++index;
//    }
//
//    return isMask0 ? ~result : result;
//}
//
//int main()
//{
//    regex maskRegex("mask = ([X10]{36})");
//    regex instructionRegex("mem\\[([0-9]+)\\] = ([0-9]+)");
//
//    ll mask0{ 0 }; // put just 0s here and do and
//    ll mask1{ 0 }; // put just 1s here and do or
//
//    map<ll, ll> memory;
//
//    string line;
//    while (getline(cin, line))
//    {
//        if (smatch match; regex_search(line, match, maskRegex))
//        {
//            string maskString{ match[1] };
//            mask0 = parseMask(maskString, true);
//            mask1 = parseMask(maskString, false);
//        }
//        else if (regex_search(line, match, instructionRegex))
//        {
//            ll memAddress{ stoll(match[1]) };
//            ll value{ stoll(match[2]) };
//
//            value &= mask0;
//            value |= mask1;
//
//            if (memory.contains(memAddress))
//            {
//                memory.at(memAddress) = value;
//            }
//            else
//            {
//                memory.emplace(memAddress, value);
//            }
//        }
//    }
//
//    ll total{ 0 };
//    for (const auto& p : memory)
//    {
//        total += p.second;
//    }
//
//    cout << total << endl;
//
//    return 0;
//}
