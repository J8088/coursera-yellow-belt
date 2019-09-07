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
#include <random>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "{";
	bool first = true;
	for (const auto& x : v) {
		if (!first) {
			out << ", ";
		}
		first = false;
		out << x;
	}
	return out << "}";
}

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
	out << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			out << ", ";
		}
		first = false;
		out << x;
	}
	return out << "}";
}

template <typename K, typename V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
	out << "{";
	bool first = true;
	for (const auto& item : m) {
		if (!first) {
			out << ", ";
		}
		first = false;
		out << item.first << ": " << item.second;
	}
	return out << "}";
}

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string hint = {}) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <typename TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (const exception& ex) {
			++fail_count;
			cerr << test_name << " fail: " << ex.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught " << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " tests failed" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}
	string GetFullName(int year) {
		string latest_name, latest_surname;
		for (const auto& item : names) {
			if ((item.first <= year) && item.second.size()) {
				latest_name = item.second;
			}
		}

		for (const auto& item : surnames) {
			if ((item.first <= year) && item.second.size()) {
				latest_surname = item.second;
			}
		}

		if (!latest_name.size() && !latest_surname.size()) {
			return "Incognito";
		}
		else if (!latest_name.size()) {
			return latest_surname + " with unknown first name";
		}
		else if (!latest_surname.size()) {
			return latest_name + " with unknown last name";
		}
		else {
			return latest_name + " " + latest_surname;
		}
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};

void TestIncognito() {
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeFirstName(1991, "b");
		p.ChangeFirstName(1992, "c");
		AssertEqual(p.GetFullName(1900), "Incognito", "incognito1");
		AssertEqual(p.GetFullName(1989), "Incognito", "incognito2");
	}
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeFirstName(1992, "c");
		AssertEqual(p.GetFullName(1900), "Incognito", "incognito3");
		AssertEqual(p.GetFullName(1989), "Incognito", "incognito4");
	}
	{
		Person p;
		p.ChangeLastName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeLastName(1992, "c");
		AssertEqual(p.GetFullName(1900), "Incognito", "incognito5");
		AssertEqual(p.GetFullName(1989), "Incognito", "incognito6");
	}
}

void TestUnknownFirstName() {
	{
		Person p;
		p.ChangeLastName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeLastName(1992, "c");
		AssertEqual(p.GetFullName(1990), "a with unknown first name", "unkownfirst1");
		AssertEqual(p.GetFullName(1991), "b with unknown first name", "unkownfirst2");
		AssertEqual(p.GetFullName(1992), "c with unknown first name", "unkownfirst3");
		AssertEqual(p.GetFullName(2000), "c with unknown first name", "unkownfirst4");
	}
	{
		Person p;
		p.ChangeLastName(1990, "a");
		p.ChangeFirstName(1991, "b");
		p.ChangeLastName(1992, "c");
		AssertEqual(p.GetFullName(1990), "a with unknown first name", "unkownfirst5");
		AssertEqual(p.GetFullName(1991), "b a", "unkownfirst6");
		AssertEqual(p.GetFullName(1992), "b c", "unkownfirst7");
		AssertEqual(p.GetFullName(2000), "b c", "unkownfirst8");
	}
}

void TestUnknownLastName() {
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeFirstName(1991, "b");
		p.ChangeFirstName(1992, "c");
		AssertEqual(p.GetFullName(1990), "a with unknown last name", "unkownlast1");
		AssertEqual(p.GetFullName(1991), "b with unknown last name", "unkownlast2");
		AssertEqual(p.GetFullName(1992), "c with unknown last name", "unkownlast3");
		AssertEqual(p.GetFullName(2000), "c with unknown last name", "unkownlast4");
	}
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeLastName(1992, "c");
		p.ChangeFirstName(1992, "b");
		AssertEqual(p.GetFullName(1990), "a with unknown last name", "unkownlast5");
		AssertEqual(p.GetFullName(1991), "a b", "unkownlast6");
		AssertEqual(p.GetFullName(1992), "b c", "unkownlast7");
		AssertEqual(p.GetFullName(2000), "b c", "unkownlast8");
	}
}

void TestNormal() {
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeFirstName(1992, "c");
		p.ChangeLastName(1993, "Smit");
		p.ChangeFirstName(2000, "John");
		AssertEqual(p.GetFullName(1991), "a b", "normal1");
		AssertEqual(p.GetFullName(1992), "c b", "normal2");
		AssertEqual(p.GetFullName(1993), "c Smit", "normal3");
		AssertEqual(p.GetFullName(1994), "c Smit", "normal4");
		AssertEqual(p.GetFullName(2000), "John Smit", "normal5");
		AssertEqual(p.GetFullName(2100), "John Smit", "normal6");
	}
	{
		Person p;
		p.ChangeFirstName(1990, "a");
		p.ChangeLastName(1991, "b");
		p.ChangeFirstName(1992, "c");
		p.ChangeLastName(1800, "Smit");
		p.ChangeFirstName(1000, "John");
		AssertEqual(p.GetFullName(1980), "John Smit", "normal7");
		AssertEqual(p.GetFullName(1990), "a Smit", "normal8");
		AssertEqual(p.GetFullName(1991), "a b", "normal9");
		AssertEqual(p.GetFullName(1992), "c b", "normal10");
		AssertEqual(p.GetFullName(2000), "c b", "normal11");
		AssertEqual(p.GetFullName(1000), "John with unknown last name", "normal12");
		AssertEqual(p.GetFullName(100), "Incognito", "normal13");
		AssertEqual(p.GetFullName(1900), "John Smit", "normal14");
	}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestIncognito, "TestIncognito");
	tr.RunTest(TestUnknownFirstName, "TestUnknownFirstName");
	tr.RunTest(TestUnknownLastName, "TestUnknownLastName");
	tr.RunTest(TestNormal, "TestNormal");
}

int main() {
	TestAll();

	return 0;
}
