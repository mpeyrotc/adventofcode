#pragma once

#include <utility>

using namespace std;

pair<int, int> Scale(pair<int, int> point, int xFactor, int yFactor)
{
    return make_pair(point.first * xFactor, point.second * yFactor);
}

pair<int, int> Move(pair<int, int> origin, pair<int, int> direction)
{
    return make_pair(origin.first + direction.first, origin.second + direction.second);
}

int ManhattanDistance(pair<int, int> pos1, pair<int, int> pos2)
{
    return abs(pos2.first - pos1.first) + abs(pos2.second - pos1.second);
}

//pair<int, int> RotateLeftByXDegreesFromOrigin(pair<int, int> origin, int degrees)
//{
//    int newX1 = origin.first * round(cos(degrees));
//    int newX2 = -origin.second * round(sin(degrees));
//    int newX = newX1 + newX2;
//    int newY = origin.second * round(cos(degrees)) - origin.first * round(sin(degrees));
//
//    return make_pair(newX, newY);
//}