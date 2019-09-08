#include "bus_manager.h"

#include <iostream>

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops[bus] = stops;
	for (const string& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	if (!stops_to_buses.count(stop)) {
		return {};
	}

	return { stops_to_buses.at(stop) };
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	if (!buses_to_stops.count(bus)) {
		return {};
	}

	vector<pair<string, vector<string>>> result;
	for (const string& stop : buses_to_stops.at(bus)) {
		result.push_back({ stop, stops_to_buses.at(stop) });
	}

	return { bus, result };
}

AllBusesResponse BusManager::GetAllBuses() const {
	return { buses_to_stops };
}
