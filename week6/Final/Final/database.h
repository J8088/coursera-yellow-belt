#pragma once

#include "date.h"

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using DateAndEvent = std::pair<Date, std::string>;

std::ostream& operator<<(std::ostream& stream, const DateAndEvent& date_and_event);

struct DateEntries {
	std::vector<std::string> events;
	std::set<std::string> unique_events;
};

class Database {
public:
	void Add(const Date& date, const std::string& event);

	template <typename Func>
	int RemoveIf(Func predicate);
	
	template <typename Func>
	std::vector<DateAndEvent> FindIf(Func predicate) const;

	void Print(std::ostream& out) const;

	DateAndEvent Last(const Date& date) const;
private:
	std::map<Date, DateEntries> events;
};

template <typename Func>
int Database::RemoveIf(Func predicate) {
	int removed = 0;
	for (auto it = events.begin(); it != events.end(); ) {
		const Date& date = it->first;
		auto& date_events = it->second.events;
		auto& unique_events = it->second.unique_events;

		auto new_end = stable_partition(begin(date_events), end(date_events), [&](const auto& event) {
			return !predicate(date, event);
		});
		removed += static_cast<int>(date_events.end() - new_end);

		for (auto erased_it = new_end; erased_it != date_events.end(); erased_it++) {
			unique_events.erase(*erased_it);
		}
		date_events.erase(new_end, date_events.end());

		if (!events[date].events.size()) {
			it = events.erase(it);
		} else {
			it++;
		}
	}

	return removed;
}

template <typename Func>
std::vector<DateAndEvent> Database::FindIf(Func predicate) const {
	std::vector<DateAndEvent> found_entries;
	for (const auto& item : events) {
		const Date& date = item.first;
		const auto& date_events = item.second.events;
		for (const auto& event : date_events) {
			if (predicate(date, event)) {
				found_entries.push_back({ date, event });
			}
		}
	}

	return found_entries;
}
