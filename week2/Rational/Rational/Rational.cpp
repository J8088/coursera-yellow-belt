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

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int p, int q) {
		int d = gcd(p, q);
		p /= d;
		q /= d;

		if (q < 0) {
			p = -p;
			q = -q;
		}

		numerator = p;
		denominator = q;
	}

	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}
private:
	int numerator;
	int denominator;
};

void TestDefault() {
	{
		Rational r;
		AssertEqual(r.Numerator(), 0, "default1");
		AssertEqual(r.Denominator(), 1, "default2");
	}
}

void TestFractionReduction() {
	{
		Rational r(14, 5);
		AssertEqual(r.Numerator(), 14, "reduction1");
		AssertEqual(r.Denominator(), 5, "reduction2");
	}
	{
		Rational r(14, 7);
		AssertEqual(r.Numerator(), 2, "reduction3");
		AssertEqual(r.Denominator(), 1, "reduction4");
	}
	{
		Rational r(-5, 14);
		AssertEqual(r.Numerator(), -5, "reduction5");
		AssertEqual(r.Denominator(), 14, "reduction6");
	}
	{
		Rational r(-7, 21);
		AssertEqual(r.Numerator(), -1, "reduction7");
		AssertEqual(r.Denominator(), 3, "reduction8");
	}
}

void TestSigns() {
	{
		Rational r(-2, 8);
		AssertEqual(r.Numerator(), -1, "negative1");
		AssertEqual(r.Denominator(), 4, "negative2");
	}
	{
		Rational r(2, -8);
		AssertEqual(r.Numerator(), -1, "negative3");
		AssertEqual(r.Denominator(), 4, "negative4");
	}
	{
		Rational r(1, -4);
		AssertEqual(r.Numerator(), -1, "negative5");
		AssertEqual(r.Denominator(), 4, "negative6");
	}
	{
		Rational r(0, -4);
		AssertEqual(r.Numerator(), 0, "negative7");
		AssertEqual(r.Denominator(), 1, "negative8");
	}
	{
		Rational r(0, 2);
		AssertEqual(r.Numerator(), 0, "negative9");
		AssertEqual(r.Denominator(), 1, "negative10");
	}
	{
		Rational r(-2, -4);
		AssertEqual(r.Numerator(), 1, "negative11");
		AssertEqual(r.Denominator(), 2, "negative12");
	}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestDefault, "TestDefault");
	tr.RunTest(TestFractionReduction, "TestFractionReduction");
	tr.RunTest(TestSigns, "TestSigns");
}

int main() {
	TestAll();

	return 0;
}
