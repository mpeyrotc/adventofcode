#include <string>
#include "Helpers.h"

int main()
{
	vector<vector<char>> initialSeats;

	string line;
	while (getline(cin, line))
	{
		vector<char> rowSeats(begin(line), end(line));
		initialSeats.push_back(rowSeats);
	}

	WaitingAreaState areaState(initialSeats);
	do
	{
		areaState = areaState.NextState(areaState.m_seats.size(), 5);
		cout << areaState.CountSeatsOfType('#') << " " << areaState.CountSeatsOfType('.') << " " << areaState.CountSeatsOfType('L') << endl;
	} while (!areaState.m_isSameAsPrevious);

	cout << areaState.CountSeatsOfType('#') << endl;
	return 0;
}