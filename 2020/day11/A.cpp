#include <string>
#include "Helpers.h"

int main2()
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
		areaState = areaState.NextState(1, 4);
	} while(!areaState.m_isSameAsPrevious);

	cout << areaState.CountSeatsOfType('#') << endl;

	return 0;
}
