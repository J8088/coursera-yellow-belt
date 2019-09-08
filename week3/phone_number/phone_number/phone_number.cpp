#include "phone_number.h"

#include <string>
#include <sstream>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
	stringstream ss(international_number);
	char plus = ss.get();
	getline(ss, country_code_, '-');
	getline(ss, city_code_, '-');
	getline(ss, local_number_);

	if (plus != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		stringstream serr;
		serr << "Wrong number format: " << international_number;
		throw invalid_argument(serr.str());
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
