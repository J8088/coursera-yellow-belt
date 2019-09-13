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
#include <memory>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

const double PI = 3.14;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Circle : public Figure {
public:
	Circle(double radius)
		: radius_(radius)
	{}

	string Name() const override {
		return "CIRCLE";
	}

	double Perimeter() const override {
		return 2 * PI * radius_;
	}

	double Area() const override {
		return PI * radius_ * radius_;
	}

private:
	double radius_;
};

class Rect : public Figure {
public:
	Rect(double width, double height)
		: width_(width)
		, height_(height)
	{}

	string Name() const override {
		return "RECT";
	}

	double Perimeter() const override {
		return 2 * (width_ + height_);
	}

	double Area() const override {
		return width_ * height_;
	}

private:
	double width_, height_;
};

class Triangle : public Figure {
public:
	Triangle(double a, double b, double c)
		: a_(a)
		, b_(b)
		, c_(c)
	{}

	string Name() const override {
		return "TRIANGLE";
	}

	double Perimeter() const override {
		return a_ + b_ + c_;
	}

	double Area() const override {
		const double p = Perimeter() / 2.0;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

private:
	double a_, b_, c_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
	string name;
	is >> name;
	if (name == "CIRCLE") {
		double r;
		is >> r;
		return make_shared<Circle>(r);
	}
	else if (name == "RECT") {
		double w, h;
		is >> w >> h;
		return make_shared<Rect>(w, h);
	}
	else {
		double a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}

	return 0;
}
