#include <iostream>
#include <string>

using namespace std;

int main()
{
    int treeCounter{ 0 };
    int row{ 1 };
    const int colDelta{ 3 };

    string line;

    getline(cin, line); // we skip the first line.
    while (getline(cin, line) && !line.empty())
    {
        if (line[(row * colDelta) % line.size()] == '#')
        {
            ++treeCounter;
        }

        ++row;
    }

    cout << treeCounter << endl;

    return 0;
}
