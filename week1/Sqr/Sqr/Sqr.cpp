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

template <typename F, typename S> pair<F, S> operator*(const pair<F, S>& lhs, const pair<F, S>& rhs);
template <typename T> vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs);
template <typename K, typename V> map<K, V> operator*(const map<K, V>& lhs, const map<K, V>& rhs);
template <typename T> T Sqr(T x);

template <typename F, typename S>
pair<F, S> operator*(const pair<F, S>& lhs, const pair<F, S>& rhs) {
	return { lhs.first * rhs.first, lhs.second * rhs.second };
}

template <typename T>
vector<T> operator*(const vector<T>& lhs, const vector<T>& rhs) {
	if (lhs.size() != rhs.size()) {
		throw invalid_argument("vectors must have equal sizes");
	}

	int n = lhs.size();
	vector<T> prod(n);
	fr2(i, 0, n) prod[i] = lhs[i] * rhs[i];

	return prod;
}

template <typename K, typename V>
map<K, V> operator*(const map<K, V>& lhs, const map<K, V>& rhs) {
	if (lhs.size() != rhs.size()) {
		throw invalid_argument("maps must have equal sizes");
	}

	map<K, V> prod;
	for (const auto& [key, lhs_value] : lhs) {
		const auto& rhs_value = rhs.at(key);
		prod[key] = lhs_value * rhs_value;
	}

	return prod;
}

template <typename T>
T Sqr(T x) {
	return x * x;
}

int main() {
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
		{ 4,{ 2, 2 } },
	{ 7,{ 4, 3 } }
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	return 0;
}
