#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	vector<int> jolts{ 0 };

	string line;
	while (getline(cin, line))
	{
		jolts.push_back(stoi(line));
	}

	sort(jolts.begin(), jolts.end());

	// Add device jolt
	jolts.push_back(*(jolts.cend() - 1) + 3);

	// Will used to keep track of previous combinations via DP.
	vector<ll> combinations(jolts.size());

	// There is at least one combination since we already past part 1.
	combinations.at(0) = 1; 

	for (int i{ 0 }; i < jolts.size(); ++i)
	{
		for (int j{ i + 1 }; j <= (i + 3) && j < jolts.size(); ++j)
		{
			if ((jolts.at(j) - jolts.at(i)) <= 3)
			{
				combinations.at(j) += combinations.at(i);
			}
		}
	}

	cout << *(combinations.cend() - 1) << endl;

	return 0;
}