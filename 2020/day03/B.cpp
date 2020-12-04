#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Slope
{
    int right;
    int down;
};

int countTrees(vector<string> forest, Slope slope)
{
    int count{ 0 };
    for (int i = slope.down, timesMovedDown{ 1 }; i < forest.size(); i += slope.down, ++timesMovedDown)
    {
        if (forest[i][(slope.right * timesMovedDown) % forest[i].size()] == '#')
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    vector<Slope> slopes{
        Slope{1, 1},
        Slope{3, 1},
        Slope{5, 1},
        Slope{7, 1},
        Slope{1, 2}
    };

    vector<string> forest;

    string line;
    while (getline(cin, line) && !line.empty())
    {
        forest.push_back(line);
    }

    long long totalTreeCount{ 1 };
    for (int i = 0; i < slopes.size(); ++i)
    {
        int treeCount{ countTrees(forest, slopes[i]) };
        totalTreeCount *= treeCount;
    }

    cout << totalTreeCount << endl;

    return 0;
}
