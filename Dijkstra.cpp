#include "Dijkstra.h"

int Dijkstra::getLowerCostIndex(std::vector<Point>& list)
{
	int minCost = INT_MAX;
	int indexMin = INT_MAX;
	for (size_t i = 0; i < listOfPoint.size(); ++i)
		if (list.at(i).getState() != Point::VISITED && listOfPoint.at(i) < minCost)
		{
			minCost =  listOfPoint.at(i);
			indexMin = i;
		}
	return indexMin;
}

Dijkstra::Dijkstra(std::vector<Point> list, int startPoint, int endPoint)
{
	
	startDot = startPoint;
	endDot = endPoint;
	list.at(startPoint).setCost(0);
	/*fill table with costs*/
	for (auto el : list)
		listOfPoint.emplace(std::make_pair(el.getNumber(), el.getCost()));
	Point* currentPoint = &list.at(startPoint);
	/*visiting dots in Dijkstra*/
	while (list[endPoint].getState() != Point::VISITED)
	{
		auto currentRoads = currentPoint->getRoads();
		for (size_t i = 0; i < listOfPoint.size(); ++i)
		{
			if (list.at(i).getState() != Point::VISITED)
				if (currentRoads.at(i) != INT_MAX)
					if (currentPoint->getCost() + currentRoads.at(i) < listOfPoint.at(i))
					{
						listOfPoint.at(i) = (currentPoint->getCost() + currentRoads.at(i));
						list.at(i).setCost(listOfPoint.at(i));
					}
		}
		currentPoint->setVisited();
		int nextIndex = getLowerCostIndex(list);
		if (nextIndex == INT_MAX && list[endPoint].getState() != Point::VISITED)
		{
			minCost = INT_MAX;
			break;
		}
		if (nextIndex != INT_MAX)
			currentPoint = &list.at(nextIndex);
	}
	if (list[endPoint].getState() == Point::VISITED)
		minCost = listOfPoint.at(endPoint);
}

void Dijkstra::outPrint()
{
	std::cout << "minimum cost from " << startDot << " to " << endDot << " = " << minCost;
}

int Dijkstra::getMinCost()
{
	return minCost;
}
