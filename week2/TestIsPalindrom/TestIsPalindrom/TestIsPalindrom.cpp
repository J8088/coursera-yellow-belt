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

bool IsPalindrom(const string& x) {
	int n = x.size();
	for (int i = 0; i < n / 2; i++) {
		if (x[i] != x[n - i - 1]) {
			return false;
		}
	}

	return true;
}

void TestPredefined() {
	Assert(IsPalindrom(""), "empty");
	Assert(IsPalindrom("a"), "1 symbol");
	Assert(IsPalindrom(" "), "1 space");
	Assert(IsPalindrom("ab ba"), "2 words");
	Assert(IsPalindrom("abba"), "abba");
	Assert(!IsPalindrom("abba  "), "abba with space in end");
	Assert(IsPalindrom("  abba  "), "abba with space in both ends");
	Assert(IsPalindrom("123321"), "numbers");
	Assert(!IsPalindrom("sdfs_klj"), "random symbols");
	Assert(IsPalindrom("sdfs_sfds"), "random symbols but palindrom");
	Assert(IsPalindrom("sdfs sfds"), "random symbols with space but palindrom");
	Assert(!IsPalindrom("bba"), "ignore first symbol");
	Assert(!IsPalindrom("abb"), "ignore last symbol");
	Assert(IsPalindrom("aba"), "odd length");
	Assert(IsPalindrom("ababa"), "odd length2");
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestPredefined, "TestPredefined");
}

int main() {
	TestAll();

	return 0;
}
