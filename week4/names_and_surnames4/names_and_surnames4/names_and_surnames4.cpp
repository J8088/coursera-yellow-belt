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

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}
	string GetFullName(int year) {
		auto latest_name_it = names.upper_bound(year),
			latest_surname_it = surnames.upper_bound(year);

		if (latest_name_it == names.begin() && latest_surname_it == surnames.begin()) {
			return "Incognito";
		}
		else if (latest_name_it == names.begin()) {
			return prev(latest_surname_it)->second + " with unknown first name";
		}
		else if (latest_surname_it == surnames.begin()) {
			return prev(latest_name_it)->second + " with unknown last name";
		}
		else {
			return prev(latest_name_it)->second + " " + prev(latest_surname_it)->second;
		}
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
