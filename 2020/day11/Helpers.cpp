#include "Helpers.h"

WaitingAreaState WaitingAreaState::NextState(const int lookAheadRange, const int occupiedSeats)
{
	vector<vector<char>> nextSeats(m_seats.size(), vector<char>(m_seats.at(0).size()));
	bool isSameAsPrevious{ true };

	for (size_t row{ 0 }; row < m_seats.size(); ++row)
	{
		for (size_t col{ 0 }; col < m_seats.at(0).size(); ++col)
		{
			char nextSeat{ NextSeat(row, col, lookAheadRange, occupiedSeats) };

			if (nextSeat != m_seats.at(row).at(col))
			{
				isSameAsPrevious = false;
			}

			nextSeats.at(row).at(col) = nextSeat;
		}
	}

	return WaitingAreaState(nextSeats, isSameAsPrevious);
}

size_t WaitingAreaState::CountSeatsOfType(const char& type)
{
	size_t result{ 0 };

	for (size_t row{ 0 }; row < m_seats.size(); ++row)
	{
		for (size_t col{ 0 }; col < m_seats.at(0).size(); ++col)
		{
			if (m_seats.at(row).at(col) == type)
			{
				++result;
			}
		}
	}

	return result;
}

WaitingAreaState& WaitingAreaState::operator=(const WaitingAreaState& other) // copy assignment
{
	if (this != &other) { // self-assignment check expected
		m_seats = other.m_seats;
		m_isSameAsPrevious = other.m_isSameAsPrevious;
	}

	return *this;
}

void WaitingAreaState::Print()
{
	unsigned int result{ 0 };

	for (size_t row{ 0 }; row < m_seats.size(); ++row)
	{
		for (size_t col{ 0 }; col < m_seats.at(0).size(); ++col)
		{
			cout << m_seats.at(row).at(col);
		}

		cout << endl;
	}
}
char WaitingAreaState::NextSeat(const size_t& row, const size_t& col, const int lookAheadRange, const int occupiedSeats)
{
	switch (const char seat{ m_seats.at(row).at(col) }; seat)
	{
	case '.':
		return seat;
	case 'L':
		return AdjacentSeatsWithState('#', row, col, lookAheadRange) == 0 ? '#' : seat;
	case '#':
		return AdjacentSeatsWithState('#', row, col, lookAheadRange) >= occupiedSeats ? 'L' : seat;
	}
}

bool IsAdjacentVisibleSeatOccupied(vector<vector<char>> seats, int i, int j, int iInc, int jInc)
{
	int x = i;
	int y = j;
	int c{ 0 };
	while (true)
	{
		x += iInc;
		y += jInc;

		if (x < 0 || y < 0 || x >= seats.size() || y >= seats.at(0).size())
		{
			return false;
		}

		if (seats[x][y] == 'L')
		{
			return false;
		}
		if (seats[x][y] == '#')
		{
			return true;
		}
	}
}

unsigned int WaitingAreaState::AdjacentSeatsWithState(const char expectedValue, const int row, const int col, const int lookAheadRange)
{
	unsigned int result{ 0 };

	//// check left side
	//for (int i{ 1 }; (col - i) >= 0; ++i)
	//{
	//	if (m_seats.at(row).at(col - i) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row).at(col - i) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check right side
	//for (int i{ 1 }; col + i < m_seats.size(); ++i)
	//{
	//	if (m_seats.at(row).at(col + i) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row).at(col + i) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check up side
	//for (int i{ 1 }; (row - i) >= 0; ++i)
	//{
	//	if (m_seats.at(row - i).at(col) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row - i).at(col) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check down side
	//for (int i{ 1 }; row + i < m_seats.size(); ++i)
	//{
	//	if (m_seats.at(row + i).at(col) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row + i).at(col) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check left upper diagonal
	//for (int i{ 1 };  (col - i) >= 0 && (row - i) >= 0 ; ++i)
	//{
	//	if (m_seats.at(row - i).at(col - i) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row - i).at(col - i) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check right upper diagonal
	//for (int i{ 1 }, j{ 1 }; (col + j) < static_cast<int>(m_seats.size()) && (row - i) >= 0; ++i, ++j)
	//{
	//	if (m_seats.at(row - i).at(col + j) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row - i).at(col + j) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check down left diagonal
	//for (int i{ 1 }, j{ 1 }; (col - j) >= 0 && (row + i) < static_cast<int>(m_seats.size()); ++i, ++j)
	//{
	//	if (m_seats.at(row + i).at(col - j) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row + i).at(col - j) != '.')
	//	{
	//		break;
	//	}
	//}

	//// check down rigth diagonal
	//for (int i{ 1 }; (col + i) < static_cast<int>(m_seats.size()) && (row + i) < static_cast<int>(m_seats.size()); ++i)
	//{
	//	if (m_seats.at(row + i).at(col + i) == expectedValue)
	//	{
	//		++result;
	//		break;
	//	}
	//	else if (m_seats.at(row + i).at(col + i) != '.')
	//	{
	//		break;
	//	}
	//}

	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, 0, -1))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, 0, 1))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, 1, 0))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, -1, 0))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, -1, -1))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, -1, 1))
	{
		result++;

	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, 1, -1))
	{
		result++;
	}
	if (IsAdjacentVisibleSeatOccupied(m_seats, row, col, 1, 1))
	{
		result++;
	}

	return result;
}
