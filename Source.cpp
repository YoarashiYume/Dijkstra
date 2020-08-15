#include "Reader.h"
#include "Dijkstra.h"
int main(int argc, char* argv[])
{
	if (argc < 5) {
		std::cout << "usage: <prog-name> <input.txt> <numberOfPoints> <startDot>  <endDot>\n";
		std::system("pause");
		return 1;
	}
	std::string path = argv[1];
	int size = std::atoi(argv[2]);
	int start = std::atoi(argv[3]);
	int end = std::atoi(argv[4]);
	
	/*Reader read("input.txt", 5);
	Dijkstra dijkstra(read.getList(), 0, 3);*/
	Reader read(path, size);
	Dijkstra dijkstra(read.getList(), start, end);
	dijkstra.outPrint();
}