#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main2()
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

	vector<ll> combinations(jolts.size());
	// There is at least one combination since we already past part 1.
	combinations.at(0) = 1; 

	for (int i{ 1 }; i < jolts.size(); ++i)
	{
		ll currentCombinationCount{ 0 };
		for (int j{ i }; j >= (i - 3) && j >= 0; --j)
		{
			if (abs(jolts.at(i) - jolts.at(j)) <= 3)
			{
				currentCombinationCount += combinations.at(j);
			}
			else
			{
				break;
			}
		}

		combinations.at(i) = currentCombinationCount;
	}

	cout << combinations.at(combinations.size() - 1) << endl;

	return 0;
}