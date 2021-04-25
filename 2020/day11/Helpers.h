#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <vector>

using namespace std;

class WaitingAreaState
{
public:
	vector<vector<char>> m_seats;
	bool m_isSameAsPrevious;

	WaitingAreaState(vector<vector<char>> seats) :
		WaitingAreaState(seats, true)
	{
	}

	WaitingAreaState(vector<vector<char>> seats, bool isSameAsPrevious) :
		m_seats(seats), m_isSameAsPrevious(isSameAsPrevious)
	{
	}

	WaitingAreaState NextState(const int lookAheadRange, const int occupiedSeats);

	size_t CountSeatsOfType(const char& type);

	WaitingAreaState& operator=(const WaitingAreaState& other);

	void Print();

private:
	char NextSeat(const size_t& row, const size_t& col, const int lookAheadRange, const int occupiedSeats);

	unsigned int AdjacentSeatsWithState(const char expectedValue, const int row, const int col, const int lookAheadRange);
};

#endif