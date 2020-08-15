#ifndef _DIJHSTRA_H_
#define _DIJHSTRA_H_
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include "Point.h"
class Dijkstra
{
private:
	std::map<int,int> listOfPoint;
	int getLowerCostIndex(std::vector<Point> & list);
	int minCost;
	int startDot, endDot;
public:
	Dijkstra(std::vector<Point> list, int startPoint, int endPoint);
	void outPrint();
	int getMinCost();
};
#endif // !_DIJHSTRA_H_
