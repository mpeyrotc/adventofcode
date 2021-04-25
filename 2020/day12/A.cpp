//#include <iostream>
//#include <string>
//#include "Helpers.h"
//
//using namespace std;
//
//int main()
//{
//    auto position{ make_pair(0, 0) };
//    auto shipDirection{ 0 };
//
//    string line;
//    while (getline(cin, line))
//    {
//        int magnitude{ stoi(line.substr(1)) };
//
//        pair<int, int> moveDirection;
//        switch (char instruction{ line.at(0) }; instruction)
//        {
//        case 'F':
//            if (shipDirection == 0)
//            {
//                moveDirection = make_pair(magnitude, 0); // east
//            }
//            else if (shipDirection == -90 || shipDirection == 270) // south
//            {
//                moveDirection = make_pair(0, -magnitude);
//            }
//            else if (shipDirection == -180 || shipDirection == 180) // west
//            {
//                moveDirection = make_pair(-magnitude, 0);
//            }
//            else
//            {
//                moveDirection = make_pair(0, magnitude); // north
//            }
//            break;
//         case 'N':
//            moveDirection = make_pair(0, magnitude);
//            break;
//        case 'E':
//            moveDirection = make_pair(magnitude, 0);
//            break;
//        case 'S':
//            moveDirection = make_pair(0, -magnitude);
//            break;
//        case 'W':
//            moveDirection = make_pair(-magnitude, 0);
//            break;
//        case 'R':
//            shipDirection -= magnitude;
//            shipDirection %= 360;
//            break;
//        case 'L':
//            shipDirection += magnitude;
//            shipDirection %= 360;
//            break;
//        }
//
//        position = Move(position, moveDirection);
//    }
//
//    cout << ManhattanDistance(make_pair(0,0), position) << endl;
//
//    return 0;
//}
