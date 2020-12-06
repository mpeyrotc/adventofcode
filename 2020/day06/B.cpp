#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int answeredQuestionsCount{ 0 };
    map<char, int> questions;
    int peopleInGroup{ 0 };

    string line;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            for (const char c : line)
            {
                if (questions.count(c))
                {
                    ++questions.at(c);
                }
                else
                {
                    questions.emplace(c, 1);
                }
            }

            ++peopleInGroup;
        }
        else
        {
            for (const auto pair : questions)
            {
                if (pair.second == peopleInGroup)
                {
                    ++answeredQuestionsCount;
                }
            }

            questions.clear();
            peopleInGroup = 0;
        }
    }

    cout << answeredQuestionsCount << endl;

    return 0;
}