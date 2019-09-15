#pragma once

#include <iostream>
#include <sstream>

class Date {
public:
	Date(int year, int month, int day);

	const int year_;
	const int month_;
	const int day_;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& stream, const Date& date);
Date ParseDate(std::istream& is);
