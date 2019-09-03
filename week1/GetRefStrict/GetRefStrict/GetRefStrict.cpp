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

template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, const K& k) {
	if (!m.count(k)) {
		throw runtime_error("no index");
	}

	return m[k];
}

int main() {
	map<int, string> m = { { 0, "value" } };
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl;

	return 0;
}
