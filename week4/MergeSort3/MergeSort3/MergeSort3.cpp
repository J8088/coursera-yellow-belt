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

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	int len = range_end - range_begin;
	if (len < 2) {
		return;
	}

	vector<typename RandomIt::value_type> v(range_begin, range_end);
	MergeSort(begin(v), begin(v) + len / 3);
	MergeSort(begin(v) + len / 3, begin(v) + 2 * len / 3);
	MergeSort(begin(v) + 2 * len / 3, end(v));

	vector<typename RandomIt::value_type> tmp;
	merge(begin(v), begin(v) + len / 3, begin(v) + len / 3, begin(v) + 2 * len / 3, back_inserter(tmp));
	merge(begin(tmp), end(tmp), begin(v) + 2 * len / 3, end(v), range_begin);
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
