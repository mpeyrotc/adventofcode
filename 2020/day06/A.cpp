#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int answeredQuestionsCount{ 0 };
    set<char> uniqueQuestions;

    string line;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            for (const char c : line)
            {
                uniqueQuestions.insert(c);
            }
        }
        else
        {
            answeredQuestionsCount += uniqueQuestions.size();
            uniqueQuestions.clear();
        }
    }

    cout << answeredQuestionsCount << endl;

    return 0;
}