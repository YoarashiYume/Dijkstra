#ifndef _READER_H_
#define _READER_H_
#include <vector>
#include "Point.h"
#include <fstream>
#include<iostream>
#include <string>
class Reader
{
private:
	std::vector<Point> list;
	int size;
public:
	Reader(std::string path, int size_);
	std::vector<Point>& getList();
};
#endif
