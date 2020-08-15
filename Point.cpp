#include "Point.h"

Point::Point(int number_, std::vector<int> costs)
{
	this->cost = INT_MAX;
	if (cost == 0)
		cost = INFINITY;
	this->number = number_;
	this->state = NOT_VISITED;
	/*fill in the cost of roads*/
	for (int i = 0; i < costs.size(); ++i)
	{
		if (i == number)
			roads.insert(std::make_pair(i, INT_MAX));
		roads.insert(std::make_pair(i, costs.at(i)));
	}

}

void Point::setVisited()
{
	this->state = VISITED;
}

int Point::getNumber()
{
	return number;
}

int Point::getCost()
{
	return cost;
}

void Point::setCost(int cost_)
{
	cost = cost_;
}

Point::Statement Point::getState()
{
	return state;
}

std::map<int, int>& Point::getRoads()
{
	return roads;
}
