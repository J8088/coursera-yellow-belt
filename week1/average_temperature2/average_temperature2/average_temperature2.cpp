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
	int n;
	cin >> n;

	vi a(n);
	I64 sum = 0;
	fr2(i, 0, n) {
		cin >> a[i];
		sum += a[i];
	}

	I64 avg = sum / n;

	vi b;
	fr2(i, 0, n) {
		if (a[i] > avg) {
			b.push_back(i);
		}
	}

	cout << b.size() << endl;
	fr2(i, 0, b.size()) {
		cout << b[i] << " ";
	}

	return 0;
}
