#include "responses.h"

#include <iostream>

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.empty()) {
		return os << "No stop";
	}

	for (const string& bus : r.buses) {
		os << bus << " ";
	}

	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops_and_buses.empty()) {
		return os << "No bus";
	}

	bool first = true;
	for (const auto& item : r.stops_and_buses) {
		if (!first) {
			os << endl;
		}
		first = false;

		os << "Stop " << item.first << ": ";
		if (item.second.size() == 1) {
			os << "no interchange";
		}
		else {
			for (const string& other_bus : item.second) {
				if (r.bus != other_bus) {
					os << other_bus << " ";
				}
			}
		}
	}

	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty()) {
		return os << "No buses";
	}

	bool first = true;
	for (const auto& bus_item : r.buses_to_stops) {
		if (!first) {
			os << endl;
		}
		first = false;

		os << "Bus " << bus_item.first << ": ";
		for (const string& stop : bus_item.second) {
			os << stop << " ";
		}
	}

	return os;
}
