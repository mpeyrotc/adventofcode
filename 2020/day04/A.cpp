#include <iostream>
#include <regex>
#include <string>
#include "Passport.h"

using namespace std;

int main2()
{
    regex passportRegex{ string("((byr|iyr|eyr|hgt|hcl|ecl|pid):[\\w#]+)") };

    int validPassports{ 0 };
    string line;
    string passportValues;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            passportValues += line + " ";
        }
        else
        {
            Passport newPassport;

            smatch match;
            while (regex_search(passportValues, match, passportRegex))
            {
                string key{ match.str().substr(0, 3) };
                string value{ match.str().substr(4) }; // skip :
                newPassport.AddField(key, value);

                passportValues = match.suffix();
            }

            if (newPassport.HasAllRequiredFields())
            {
                ++validPassports;
            }

            passportValues = "";
        }
    }
    
    cout << validPassports << endl;

    return 0;
}
