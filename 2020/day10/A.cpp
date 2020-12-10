#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int mai2()
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

	int jolt1{ 0 };
	int jolt3{ 0 };

	for (size_t i{ 0 }, j{ 1 }; j < jolts.size(); ++i, ++j)
	{
		int diff{ jolts.at(j) - jolts.at(i) };

		if (diff == 1)
		{
			++jolt1;
		}
		else
		{
			++jolt3;
		}
	}

	cout << (jolt1 * jolt3) << endl;

	return 0;
}
