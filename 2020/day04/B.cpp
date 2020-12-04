#include <iostream>
#include <regex>
#include <string>
#include "Passport.h"

using namespace std;

int main()
{
    regex passportRegex{ string("(byr:[0-9]{4})|") +
                                "(iyr:[0-9]{4})|" +
                                "(eyr:[0-9]{4})|" +
                                "(hgt:[0-9]+in)|" +
                                "(hgt:[0-9]+cm)|" +
                                "(hcl:#[0-9a-f]{6})|" +
                                "(ecl:(amb|blu|brn|gry|grn|hzl|oth))|" +
                                "(pid:[0-9]+)|" +
                                "\\s+\\n" };

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

            if (newPassport.HasAllRequiredFields() && newPassport.AreFieldsValid())
            {
                ++validPassports;
            }

            passportValues = "";
        }
    }

    cout << validPassports << endl;

    return 0;
}
