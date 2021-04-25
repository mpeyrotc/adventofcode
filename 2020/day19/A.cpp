#include <iostream>
#include <string>
#include <regex>
#include <map>

using namespace std;

map<int, string> rulesMap;

string ReduceMap(map<int, string> rulesMap)
{
	string resultTemp{rulesMap.at(0)};

	bool noMoreSubRulesPresent{ false };
	while (!noMoreSubRulesPresent)
	{
		noMoreSubRulesPresent = true;

		string newResult{};
		for (size_t i{ 0 }; i < resultTemp.size();)
		{
			switch (resultTemp.at(i))
			{
			case '"':
				++i;
				break;
			case 'a':
			case 'b':
			case '(':
			case ')':
			case ' ':
			case '|':
				newResult += resultTemp.at(i);
				++i;
				break;
			default:
				size_t idDigits{ resultTemp.substr(i).find_first_of(" )") };

				if (idDigits == string::npos)
				{
					idDigits = resultTemp.size() - i;
				}

				int id{ stoi(resultTemp.substr(i, idDigits)) };

				newResult += "(";
				newResult += rulesMap.at(id);
				newResult += ")";

				i += idDigits;

				noMoreSubRulesPresent = false;
			}
		}

		resultTemp = newResult;
	}

	string result;
	for (size_t i{ 0 }; i < resultTemp.size(); ++i)
	{
		if (resultTemp.at(i) != ' ')
		{
			result += resultTemp.at(i);
		}
	}

	return result;
}


int main()
{
	string line;
	while (getline(cin, line) && line != "")
	{
		size_t idDigits{ line.find(':') };
		rulesMap.emplace(stoi(line.substr(0, idDigits)), line.substr(idDigits + 2));
	}

	int count{ 0 };

	regex regexRule{ ReduceMap(rulesMap) };
	while (getline(cin, line))
	{
		smatch match;
		if (regex_match(line, match, regexRule))
		{
			++count;
		}
	}

	cout << count << endl;

	return 0;
}