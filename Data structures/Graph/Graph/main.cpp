/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
*
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
*
* © Developed by Bezukh Vladimir. All right reserved.
*/
#include "Graph.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Graph graph;
	int amountVert, amountEdge, edgeWeight;
	int vertex, initialVertex, endVertex;

	std::cout << "Введите кол-во вершин графа: "; std::cin >> amountVert;
	std::cout << "Введите кол-во рёбер графа: ";  std::cin >> amountEdge;

	for (int i = 0; i < amountVert; ++i)
	{
		std::cout << "Вершина: "; std::cin >> vertex;
		graph.addVertex(vertex);
	}

	for (int i = 0; i < amountEdge; ++i) {
		std::cout << "Исходная вершина: "; std::cin >> initialVertex;
		std::cout << "Конечная вершина: "; std::cin >> endVertex;
		std::cout << "Вес ребра: ";		   std::cin >> edgeWeight;

		graph.setEdge(initialVertex, endVertex, edgeWeight);
	}

	int start_vertex;
	std::cout << "Из какой вершины произвести поиск кратчайших путей по алгоритму Дейкстры? Введите: ";
	std::cin >> start_vertex;

	graph.printAdjacencyMatrix();
	graph.simplePathfindingAlgoritm(start_vertex);
}