#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

//enum class Lang {
//	DE, FR, IT
//};
//
//struct Region {
//	string std_name;
//	string parent_std_name;
//	map<Lang, string> names;
//	int64_t population;
//};

bool operator<(const Region& lhs, const Region& rhs) {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population)
		< tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	map<Region, int> counts;
	int max_count = 0;
	for (const auto& region : regions) {
		counts[region]++;
		max_count = max(max_count, counts[region]);
	}

	return max_count;
}

int main() {
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},
		}) << endl;

	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Russia",
			"Eurasia",
		{ { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou deux" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Toulouse",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		89
		},{
			"Moscow",
			"Russia",
		{ { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
		31
		},
		}) << endl;


	return 0;
}
