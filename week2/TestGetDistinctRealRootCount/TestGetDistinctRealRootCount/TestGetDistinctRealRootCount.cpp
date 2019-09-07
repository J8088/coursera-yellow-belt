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
	for (const auto& [key, value] : m) {
		if (!first) {
			out << ", ";
		}
		first = false;
		out << key << ": " << value;
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
		} catch (const exception& ex) {
			++fail_count;
			cerr << test_name << " fail: " << ex.what() << endl;
		} catch (...) {
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

int GetLinearEquationRootCount(double b, double c) {
	// случай a = b = c = 0 невозможен по условию
	return (b == 0) ? 0 : 1;
}

int GetQuadraticEquationRootCount(double a, double b, double c) {
	double d = b * b - 4 * a * c;

	if (d == 0) {
		return 1;
	}
	
	if (d > 0) {
		return 2;
	}

	return 0;
}

int GetDistinctRealRootCount(double a, double b, double c) {
	if (a == 0) {
		return GetLinearEquationRootCount(b, c);
	} else {
		return GetQuadraticEquationRootCount(a, b, c);
	}
}

void TestGetLinearEquationRootCount() {
	{
		AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "b = 0");
		AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "c = 0");
		AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "b != 0 and c != 0");
	}
}

void TestGetQuadraticEquationRootCount() {
	{
		AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "b = 0 and c > 0");
		AssertEqual(GetDistinctRealRootCount(1, 0, -1), 2, "b = 0 and c < 0");
		AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "b = 0 and c = 0");
		AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, "b > 0 and c = 0");
		AssertEqual(GetDistinctRealRootCount(1, -1, 0), 2, "b < 0 and c = 0");
		AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "D < 0");
		AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "D = 0");
		AssertEqual(GetDistinctRealRootCount(1, 3, 1), 2, "D > 0");
		AssertEqual(GetDistinctRealRootCount(-1, 2, 1), 2, "a < 0, D > 0");
	}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestGetLinearEquationRootCount, "TestGetLinearEquationRootCount");
	tr.RunTest(TestGetQuadraticEquationRootCount, "TestGetQuadraticEquationRootCount");
}

int main() {
	TestAll();

	return 0;
}
