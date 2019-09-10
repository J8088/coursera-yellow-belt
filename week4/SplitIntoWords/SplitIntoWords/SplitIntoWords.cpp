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

vector<string> SplitIntoWords(const string& s) {
	auto prev_it = s.begin(), it = s.begin();
	vector<string> res;
	while (it != s.end()) {
		it = find(prev_it, s.end(), ' ');
		res.push_back(string(prev_it, it));
		prev_it = find_if(it, s.end(), [](char x) { return x != ' '; });
	}

	return res;
}

int main() {
	string s = "C  Cpp  Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}
