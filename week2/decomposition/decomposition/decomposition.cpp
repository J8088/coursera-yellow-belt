#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string cmd;
	is >> cmd;
	if (cmd == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (string& stop : q.stops) {
			is >> stop;
		}
	}
	else if (cmd == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (cmd == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (cmd == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.empty()) {
		return os << "No stop";
	}

	for (const string& bus : r.buses) {
		os << bus << " ";
	}
	
	return os;
}

struct StopsForBusResponse {
	string bus;
	vector<pair<string, vector<string>>> stops_and_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops_and_buses.empty()) {
		return os << "No bus";
	}

	bool first = true;
	for (const auto& [stop, buses] : r.stops_and_buses) {
		if (!first) {
			os << endl;
		}
		first = false;

		os << "Stop " << stop << ": ";
		if (buses.size() == 1) {
			os << "no interchange";
		}
		else {
			for (const string& other_bus : buses) {
				if (r.bus != other_bus) {
					os << other_bus << " ";
				}
			}
		}
	}

	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

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

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		if (!stops_to_buses.count(stop)) {
			return {};
		}

		return { stops_to_buses.at(stop) };
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		if (!buses_to_stops.count(bus)) {
			return {};
		}

		vector<pair<string, vector<string>>> result;
		for (const string& stop : buses_to_stops.at(bus)) {
			result.push_back({ stop, stops_to_buses.at(stop) });
		}

		return { bus, result };
	}

	AllBusesResponse GetAllBuses() const {
		return { buses_to_stops };
	}
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
