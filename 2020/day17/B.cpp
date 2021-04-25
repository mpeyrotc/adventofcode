#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct IntVec4
{
    int x;
    int y;
    int z;
    int w;
};

bool operator<(const IntVec4& a, const IntVec4& b)
{
    if (a.x < b.x)
    {
        return true;
    }

    if ((a.x == b.x) && (a.y < b.y))
    {
        return true;
    }

    if ((a.x == b.x) && (a.y == b.y) && (a.z < b.z))
    {
        return true;
    }

    if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w < b.w))
    {
        return true;
    }

    return false;
}

bool operator==(const IntVec4& a, const IntVec4& b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}

struct Hash {
    size_t operator() (const IntVec4& point) const {
        size_t hash = 7;
        hash = 31 * hash + point.x;
        hash = 31 * hash + point.y;
        hash = 31 * hash + point.z;
        hash = 31 * hash + point.w;

        return hash;
    }
};

static vector<IntVec4> directions;
static unordered_set<IntVec4, Hash> activePoints;

int rangePX{ 0 };
int rangePY{ 0 };
int rangePZ{ 0 };
int rangePW{ 0 };
int rangeNX{ 0 };
int rangeNY{ 0 };
int rangeNZ{ 0 };
int rangeNW{ 0 };

void initializeDirections()
{
    for (int i{ -1 }; i <= 1; i++)
    {
        for (int j{ -1 }; j <= 1; j++)
        {
            for (int k{ -1 }; k <= 1; k++)
            {
                for (int w{ -1 }; w <= 1; w++)
                {
                    if (i == 0 && j == 0 && k == 0 && w == 0)
                    {
                        continue;
                    }

                    directions.push_back(IntVec4{ i, j, k, w });
                }
            }
        }
    }
}

void nextState()
{
    rangePX++;
    rangePY++;
    rangePZ++;
    rangePW++;
    rangeNX--;
    rangeNY--;
    rangeNZ--;
    rangeNW--;

    unordered_set<IntVec4, Hash> nextActivePoints;

    for (int i{ rangeNX }; i <= rangePX; ++i)
    {
        for (int j{ rangeNY }; j <= rangePY; ++j)
        {
            for (int k{ rangeNZ }; k <= rangePZ; ++k)
            {
                for (int w{ rangeNW }; w <= rangePW; ++w)
                {
                    if (activePoints.count(IntVec4{ i, j, k, w }) != 0)
                    {
                        // active case
                        int count{ 0 };

                        for (const auto& direction : directions)
                        {
                            IntVec4 neighbor{ i + direction.x, j + direction.y, k + direction.z, w + direction.w };

                            if (activePoints.count(neighbor) != 0)
                            {
                                ++count;
                            }
                        }

                        if (count == 2 || count == 3)
                        {
                            nextActivePoints.insert(IntVec4{ i, j, k, w });
                        }
                    }
                    else
                    {
                        // inactive case
                        int count{ 0 };

                        for (const auto& direction : directions)
                        {
                            IntVec4 neighbor{ i + direction.x, j + direction.y, k + direction.z, w + direction.w };

                            if (activePoints.count(neighbor) != 0)
                            {
                                ++count;
                            }
                        }

                        if (count == 3)
                        {
                            nextActivePoints.insert(IntVec4{ i, j, k, w });
                        }
                    }
                }
            }
        }
    }

    activePoints = nextActivePoints;
}

int main()
{
    initializeDirections();

    string line;
    while (getline(cin, line))
    {
        rangePX = 0;

        for (const auto& c : line)
        {
            // active cell
            if (c == '#')
            {
                activePoints.insert(IntVec4{ rangePX, rangePY, rangePZ, rangePW });
            }

            ++rangePX;
        }

        ++rangePY;
    }

    rangePX--;
    rangePY--;

    for (int i = 0; i < 6; i++)
    {
        nextState();
    }

}
