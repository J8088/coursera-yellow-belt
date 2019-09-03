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

class Matrix {
public:
	Matrix() {
		num_rows = 0;
		num_cols = 0;
	}
	Matrix(int nr, int nc) {
		Reset(nr, nc);
	}
	void Reset(int nr, int nc) {
		if ((nr < 0) || (nc < 0)) {
			throw out_of_range("Sizes can't be negative");
		}

		if ((nr == 0) || (nc == 0)) {
			num_rows = 0;
			num_cols = 0;
		} else {
			num_rows = nr;
			num_cols = nc;
		}

		data.assign(num_rows, vi(num_cols));
	}
	int At(int i, int j) const {
		return data.at(i).at(j);
	}
	int& At(int i, int j) {
		return data.at(i).at(j);
	}
	int GetNumRows() const {
		return num_rows;
	}
	int GetNumColumns() const {
		return num_cols;
	}
private:
	int num_rows;
	int num_cols;
	vector<vector<int>> data;
};

istream& operator>>(istream& stream, Matrix& matrix) {
	int n, m;
	stream >> n >> m;
	matrix.Reset(n, m);

	fr2(i, 0, n) {
		fr2(j, 0, m) {
			stream >> matrix.At(i, j);
		}
	}

	return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
	int n, m;
	n = matrix.GetNumRows();
	m = matrix.GetNumColumns();
	stream << n << " " << m << endl;
	fr2(i, 0, n) {
		fr2(j, 0, m) {
			stream << matrix.At(i, j);
			if (j < m - 1) stream << " ";
		}
		stream << endl;
	}

	return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
		return false;
	}

	int n, m;
	n = lhs.GetNumRows();
	m = lhs.GetNumColumns();
	fr2(i, 0, n) {
		fr2(j, 0, m) {
			if (lhs.At(i, j) != rhs.At(i, j)) {
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
		throw invalid_argument("Matrices should have equal sizes");
	}

	int n, m;
	n = lhs.GetNumRows();
	m = lhs.GetNumColumns();

	Matrix sum(n, m);
	fr2(i, 0, n) {
		fr2(j, 0, m) {
			sum.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}

	return sum;
}

int main() {
	try {
		Matrix one(0, 5), two(3, 0);
		cout << one + two << endl;
	} catch (const exception& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}
