#include "closest_pair.h"

#include <stdexcept>

using namespace std;

std::pair<Point, Point> brute_force(const std::vector<Point> &points) {
	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}	
	
	pair<Point, Point> shortest_pair = make_pair(points[0], points[1]);
	double shortest_distance = points[0].distance(points[1]);
	for (size_t i = 0; i < points.size(); i++) {
		for (size_t j = i + 1; j < points.size(); j++) {
			double current_distance = points[i].distance(points[j]);
			if (current_distance < shortest_distance) {
				shortest_distance = current_distance;
				shortest_pair = make_pair(points[i], points[j]);
			}
		}	
	}
	
	return shortest_pair;
}

std::pair<Point, Point> closest_pair(const std::vector<Point> &points) {
	// Return the closest pair of points from given points.
	// Order of points in the result doesn't matter.
	// If there are fewer than 2 points, throw an exception.

	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}	

	// Your implementation here.
	
	auto result = std::make_pair(Point(), Point());	
	return result;
}
