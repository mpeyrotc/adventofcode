//#include <iostream>
//#include <unordered_set>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct IntVec3
//{
//    int x;
//    int y;
//    int z;
//};
//
//bool operator<(const IntVec3& a, const IntVec3& b)
//{
//    if (a.x < b.x)
//    {
//        return true;
//    }
//
//    if ((a.x == b.x) && (a.y < b.y))
//    {
//        return true;
//    }
//
//    if ((a.x == b.x) && (a.y == b.y) && (a.z < b.z))
//    {
//        return true;
//    }
//
//    return false;
//}
//
//bool operator==(const IntVec3& a, const IntVec3& b)
//{
//    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
//}
//
//struct Hash {
//    size_t operator() (const IntVec3& point) const {
//        size_t hash = 7;
//        hash = 31 * hash + point.x;
//        hash = 31 * hash + point.y;
//        hash = 31 * hash + point.z;
//
//        return hash;
//    }
//};
//
//static vector<IntVec3> directions;
//static unordered_set<IntVec3, Hash> activePoints;
//
//int rangePX{ 0 };
//int rangePY{ 0 };
//int rangePZ{ 0 };
//int rangeNX{ 0 };
//int rangeNY{ 0 };
//int rangeNZ{ 0 };
//
//void initializeDirections()
//{
//    for (int i{ -1 }; i <= 1; i++)
//    {
//        for (int j{ -1 }; j <= 1; j++)
//        {
//            for (int k{ -1 }; k <= 1; k++)
//            {
//                if (i == 0 && j == 0 && k == 0)
//                {
//                    continue;
//                }
//
//                directions.push_back(IntVec3{ i, j, k });
//            }
//        } 
//    }
//}
//
//void nextState()
//{
//    rangePX++;
//    rangePY++;
//    rangePZ++;
//    rangeNX--;
//    rangeNY--;
//    rangeNZ--;
//
//    unordered_set<IntVec3, Hash> nextActivePoints;
//
//    for (int i{ rangeNX }; i <= rangePX; ++i)
//    {
//        for (int j{ rangeNY }; j <= rangePY; ++j)
//        {
//            for (int k{ rangeNZ }; k <= rangePZ; ++k)
//            {
//                if (activePoints.count(IntVec3{ i, j, k }) != 0)
//                {
//                    // active case
//                    int count{ 0 };
//
//                    for (const auto& direction : directions)
//                    {
//                        IntVec3 neighbor{ i + direction.x, j + direction.y, k + direction.z };
//
//                        if (activePoints.count(neighbor) != 0)
//                        {
//                            ++count;
//                        }
//                    }
//
//                    if (count == 2 || count == 3)
//                    {
//                        nextActivePoints.insert(IntVec3{ i, j, k });
//                    }
//                }
//                else
//                {
//                    // inactive case
//                    int count{ 0 };
//
//                    for (const auto& direction : directions)
//                    {
//                        IntVec3 neighbor{ i + direction.x, j + direction.y, k + direction.z };
//
//                        if (activePoints.count(neighbor) != 0)
//                        {
//                            ++count;
//                        }
//                    }
//
//                    if (count == 3)
//                    {
//                        nextActivePoints.insert(IntVec3{ i, j, k });
//                    }
//                }
//            }
//        }
//    }
//
//    activePoints = nextActivePoints;
//}
//
//int main()
//{
//    initializeDirections();
//
//    string line;
//    while (getline(cin, line))
//    {
//        rangePX = 0;
//
//        for (const auto& c : line)
//        {
//            // active cell
//            if (c == '#')
//            {
//                activePoints.insert(IntVec3{ rangePX, rangePY, rangePZ });
//            }
//
//            ++rangePX;
//        }
//
//        ++rangePY;
//    }
//
//    rangePX--;
//    rangePY--;
//
//    for (int i = 0; i < 6; i++)
//    {
//        nextState();
//    }
//    
//}
