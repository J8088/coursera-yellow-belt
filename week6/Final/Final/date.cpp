#include "date.h"

#include <iomanip>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.year_ == rhs.year_) {
		if (lhs.month_ == rhs.month_) {
			return lhs.day_ < rhs.day_;
		}

		return lhs.month_ < rhs.month_;
	}

	return lhs.year_ < rhs.year_;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return (lhs.year_ == rhs.year_) && (lhs.month_ == rhs.month_) && (lhs.day_ == rhs.day_);
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const Date& lhs, const Date& rhs) {
	return !(lhs <= rhs);
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return (lhs == rhs) || (lhs > rhs);
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.year_ << "-"
		<< setw(2) << setfill('0') << date.month_ << "-"
		<< setw(2) << setfill('0') << date.day_;
	return stream;
}

Date ParseDate(istream& is) {
	char hyp1, hyp2;
	int year, month, day;
	is >> year >> hyp1 >> month >> hyp2 >> day;

	if (!is) {
		throw logic_error("Wrong date format");
	}

	if ((month < 1) || (month > 12)) {
		stringstream serr;
		serr << "Month value is invalid" << month;
		throw logic_error("Month value is invalid");
	}

	if ((day < 1) || (day > 31)) {
		stringstream serr;
		serr << "Day value is invalid: " << day;
		throw logic_error(serr.str());
	}

	return Date(year, month, day);
}

Date::Date(int year, int month, int day)
	: year_(year)
	, month_(month)
	, day_(day)
{}
