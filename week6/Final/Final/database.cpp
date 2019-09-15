#include "database.h"
#include "date.h"

#include <iostream>
#include <sstream>

using namespace std;

ostream& operator<<(ostream& stream, const DateAndEvent& date_and_event) {
	stream << date_and_event.first << " " << date_and_event.second;
	return stream;
}

void Database::Add(const Date& date, const string& event) {
	auto res = events[date].unique_events.insert(event);
	if (res.second) {
		events[date].events.push_back(event);
	}
}

void Database::Print(ostream& out) const {
	for (const auto& item : events) {
		const Date& date = item.first;
		for (const string& event : item.second.events) {
			out << date << " " << event << endl;
		}
	}
}

DateAndEvent Database::Last(const Date& date) const {
	auto it = events.upper_bound(date);
	if (events.empty() || (it == events.begin())) {
		stringstream serr;
		serr << "No events with date less or equal to " << date;
		throw invalid_argument(serr.str());
	}

	it--;
	const Date& found_date = it->first;
	const vector<string>& date_events = it->second.events;

	if (date_events.empty()) {
		stringstream serr;
		serr << "No events with date less or equal to " << date;
		throw invalid_argument(serr.str());
	}

	return { found_date, date_events.back() };
}
