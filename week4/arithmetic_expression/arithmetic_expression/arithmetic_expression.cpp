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

int main() {
	int x, n;
	cin >> x >> n;

	vector<pair<char, int>> v;
	fr2(i, 0, n) {
		char op; int a;
		cin >> op >> a;
		v.push_back({ op, a });
	}

	cout << string(n, '(') << x;
	fr2(i, 0, n) {
		cout << ") " << v[i].first << " " << v[i].second;
	}

	return 0;
}
