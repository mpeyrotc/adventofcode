#include <iostream>
#include <string>
#include <vector>
#include "Helpers.h"

using namespace std;

vector<pair<int, int>> angleHelpers{ make_pair(1,1), make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1) };

int main()
{
    auto wayPointPosition{ make_pair(10, 1) };
    auto shipPosition{ make_pair(0,0) };

    int lastRotationPositon{ 0 };

    string line;
    while (getline(cin, line))
    {
        int magnitude{ stoi(line.substr(1)) };
        int rotations;

        pair<int, int> moveDirection{};
        switch (char instruction{ line.at(0) }; instruction)
        {
        case 'F':
            break;
        case 'N':
            moveDirection = make_pair(0, magnitude);
            break;
        case 'E':
            moveDirection = make_pair(magnitude, 0);
            break;
        case 'S':
            moveDirection = make_pair(0, -magnitude);
            break;
        case 'W':
            moveDirection = make_pair(-magnitude, 0);
            break;
        case 'R':
            if (wayPointPosition.first >= 0 && wayPointPosition.second >= 0)
            {
                lastRotationPositon = 0;
            }
            else if (wayPointPosition.first < 0 && wayPointPosition.second >= 0)
            {
                lastRotationPositon = 1;
            }
            else if (wayPointPosition.first < 0 && wayPointPosition.second < 0)
            {
                lastRotationPositon = 2;
            }
            else
            {
                lastRotationPositon = 3;
            }

            rotations = 4 - ((magnitude % 360) / 90);
            lastRotationPositon = (lastRotationPositon + rotations) % 4;

            if (rotations % 2 != 0) // odd inverse x and y
            {
                wayPointPosition = make_pair(abs(wayPointPosition.second), abs(wayPointPosition.first));
            }
            else
            {
                wayPointPosition = make_pair(abs(wayPointPosition.first), abs(wayPointPosition.second));
            }

            wayPointPosition = make_pair(wayPointPosition.first * angleHelpers.at(lastRotationPositon).first, wayPointPosition.second * angleHelpers.at(lastRotationPositon).second);
            break;
        case 'L':
            if (wayPointPosition.first >= 0 && wayPointPosition.second >= 0)
            {
                lastRotationPositon = 0;
            }
            else if (wayPointPosition.first < 0 && wayPointPosition.second >= 0)
            {
                lastRotationPositon = 1;
            }
            else if (wayPointPosition.first < 0 && wayPointPosition.second < 0)
            {
                lastRotationPositon = 2;
            }
            else
            {
                lastRotationPositon = 3;
            }

            rotations = (magnitude % 360) / 90;
            lastRotationPositon = (lastRotationPositon + rotations) % 4;

            if (rotations % 2 != 0) // odd inverse x and y
            {
                wayPointPosition = make_pair(abs(wayPointPosition.second), abs(wayPointPosition.first));
            }
            else
            {
                wayPointPosition = make_pair(abs(wayPointPosition.first), abs(wayPointPosition.second));
            }

            wayPointPosition = make_pair(wayPointPosition.first * angleHelpers.at(lastRotationPositon).first, wayPointPosition.second * angleHelpers.at(lastRotationPositon).second);
            break;
        }

        switch (char instruction{ line.at(0) }; instruction)
        {
        case 'F':
            shipPosition = make_pair(shipPosition.first + (wayPointPosition.first * magnitude), shipPosition.second + (wayPointPosition.second * magnitude));
            break;
        case 'N':
        case 'E':
        case 'S':
        case 'W':
            wayPointPosition = Move(wayPointPosition, moveDirection);
            break;
        case 'R':
        case 'L':
            // Nothing.
            break;
        }
    }

    // 39944
    cout << ManhattanDistance(make_pair(0, 0), shipPosition) << endl;

    return 0;
}