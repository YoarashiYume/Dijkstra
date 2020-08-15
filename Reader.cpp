#include "Reader.h"
/*reading point from file*/
Reader::Reader(std::string path, int size_)
{
	
	this->size = size_;
	std::fstream in;
	in.open(path);
	try
	{
		std::vector<int> roads;
		int number = 0;
		if (!in.is_open())
		{
			std::cout << "Exception opening/readin file";
			std::exit(1);
		}
		while (!in.eof())
		{
			if (in.eof()) break;
			if (roads.size() == size )
			{
				list.push_back(Point(number, roads));
				++number;
				roads.clear();
			}
			std::string value = "";
			in >> value;
			if (isdigit(value[0]))
				roads.push_back(std::atoi(value.c_str()));
			else
				roads.push_back(INT_MAX);
			
		}
		if (roads.size() == size)
		{
			list.push_back(Point(number, roads));
			++number;
			roads.clear();
		}
		if (roads.size() != 0)
		{
			std::cout << "incorrect size";
			std::exit(1);
		}
	
		in.close();
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << "Exception opening/readin file";
		std::exit(1);
		in.close();
	}
}

std::vector<Point>& Reader::getList()
{
	return list;
}
