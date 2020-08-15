#ifndef _POINT_H_
#define _POINT_H_
#include <map>
#include <vector>
#include <utility>
class Point
{
public:
	enum Statement {
		VISITED,
		NOT_VISITED
	};
private:
	int number;
	int cost;
	std::map<int, int> roads;
	Statement state;
public:
	Point(int number_,std::vector<int> costs);
	void setVisited();
	int getNumber();
	int getCost();
	void setCost(int cost_);
	Point::Statement getState();
	std::map<int, int>& getRoads();
};
#endif
