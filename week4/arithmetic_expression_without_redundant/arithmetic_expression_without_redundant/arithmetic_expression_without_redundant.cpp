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

struct NextOperand {
	char op;
	int val;
	bool has_brackets;
};

int priority(char op) {
	if (op == '*' || op == '/') {
		return 2;
	}

	return 1;
}

int main() {
	int x, n;
	cin >> x >> n;

	vector<NextOperand> v;
	int brackets = 0;
	fr2(i, 0, n) {
		char op; int a;
		cin >> op >> a;
		bool has_brackets = i > 0 && priority(v.back().op) < priority(op);
		v.push_back({ op, a, has_brackets });
		if (has_brackets) brackets++;
	}

	cout << string(brackets, '(') << x;
	fr2(i, 0, n) {
		cout << (v[i].has_brackets ? ") " : " ") << v[i].op << " " << v[i].val;
	}

	return 0;
}
