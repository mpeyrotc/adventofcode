#include <iostream>
#include <regex>
#include <string>
#include "Passport.h"
#include <list>

using namespace std;

bool regulateInformation(string field, string sub) {
    //cout << "Estoy en " << sub << "con " << field <<endl;
    if (sub == "byr") {
        regex rgx(".*byr:([0-9]{4}).*");
        smatch match;
        if (regex_search(field, match, rgx)) {
            if (stoi(match[1]) >= 1920 && stoi(match[1]) <= 2002) {
                return true;
            }
        }
        return false;
    }
    if (sub == "iyr") {
        regex rgx(".*iyr:([0-9]{4}).*");
        smatch match;
        if (regex_search(field, match, rgx)) {
            if (stoi(match[1]) >= 2010 && stoi(match[1]) <= 2020) {
                return true;
            }
        }
        return false;
    }

    if (sub == "eyr") {
        regex rgx(".*eyr:([0-9]{4}).*");
        smatch match;
        if (regex_search(field, match, rgx)) {
            if (stoi(match[1]) >= 2020 && stoi(match[1]) <= 2030) {
                return true;
            }
        }
        return false;
    }

    if (sub == "hgt") {
        smatch match;
        regex rgx(".*hgt:([0-9]{1,})((cm|in)).*");
        if (regex_search(field, match, rgx)) {
            string findMatch = match[2];
            char letter = findMatch.at(1);
            switch (letter) {
            case 'm': {
                if (stoi(match[1]) >= 150 && stoi(match[1]) <= 193) {
                    return true;
                }
                return false;
            }

            case 'n': {
                if (stoi(match[1]) >= 59 && stoi(match[1]) <= 76) {
                    return true;
                }
                return false;
            }
            default:
            {return false; }
            }
        }
        return false;
    }

    if (sub == "hcl") {
        regex rgx(".*hcl:#([0-9a-f]{6}).*");
        return regex_search(field, rgx);
    }

    if (sub == "ecl") {
        regex rgx(".*ecl:(amb|blu|brn|gry|grn|hzl|oth).*");
        return regex_search(field, rgx);
    }

    if (sub == "pid") {
        regex rgx(".*pid:([0-9]{9}).*");
        return regex_search(field, rgx);
    }

    return false;

}


//Obtain the value from each Field
string obtainField(string smallString) {
    string field;
    int j{};
    while (smallString.at(j) != ' ') {
        field = field + smallString.at(j);
        j++;
    }
    return field;
}




bool verifyCompleteString(string complete) {
    if (regulateInformation(complete, "byr") &&
        regulateInformation(complete, "iyr") &&
        regulateInformation(complete, "eyr") &&
        regulateInformation(complete, "hgt") &&
        regulateInformation(complete, "hcl") &&
        regulateInformation(complete, "ecl") &&
        regulateInformation(complete, "pid")) {
        return true;
    }
    return false;
}



bool findTree(int row, int column, std::list<string>::iterator iteratNum) {

    //Iterate the List.

    for (int i = 1; i < row; i++) {
        iteratNum++;
    }

    //Find String
    string path = *iteratNum;
    bool pathBool = path.at(column - 1) == '#';

    //Get Value, verify Tree
    return pathBool;
}

int correctColumn(int column, int max) {
    if (!(column > max)) {
        return column;
    }
    return correctColumn(column - max, max);
}



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
    string passportValues2;
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
            passportValues2 = passportValues;
            while (regex_search(passportValues, match, passportRegex))
            {
                string key{ match.str().substr(0, 3) };
                string value{ match.str().substr(4) }; // skip :
                newPassport.AddField(key, value);

                passportValues = match.suffix();
            }

            bool a{ false };
            if (newPassport.HasAllRequiredFields() && newPassport.AreFieldsValid())
            {
                ++validPassports;
                a = true;
            }
            
            bool b{ false };
            if (verifyCompleteString(passportValues2))
            {
                b = true;
            }

            if (a != b)
            {
                cout << passportValues << endl;
            }

            passportValues = "";
        }
    }

    cout << validPassports << endl;

    return 0;
}
