#include <map>
#include <string>

using namespace std;

class Passport
{
private:
    map<string, string> fields;

public:
    void AddField(string key, string value)
    {
        fields.emplace(key, value);
    }

    bool HasAllRequiredFields()
    {
        return fields.size() == 7;
    }

    bool AreFieldsValid()
    {
        if (int byr = stoi(fields["byr"]); (byr < 1920 || byr > 2002))
        {
            return false;
        }
        if (int iyr = stoi(fields["iyr"]); (iyr < 2010 || iyr > 2020))
        {
            return false;
        }
        if (int eyr = stoi(fields["eyr"]); (eyr < 2020 || eyr > 2030))
        {
            return false;
        }
        bool isMetric = fields["hgt"].substr(fields["hgt"].size() - 2) == "cm";
        if (int hgt = stoi(fields["hgt"].substr(0, fields["hgt"].find_last_of("ci")));
            isMetric ? (hgt < 150 || hgt > 193) : (hgt < 59 || hgt > 76))
        {
            return false;
        }
        if (fields["pid"].size() != 9)
        {
            return false;
        }

        return true;
    }
};