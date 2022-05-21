#pragma once
#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> Grid;
typedef std::vector<int> List;

class Graph
{
private:
	int size_;
	List vertices_;
	Grid adjacency_matrix;

public:
	Graph() : Graph(10) {}
	Graph(const int& size)
	{
		size_ = size;
		adjacency_matrix = Grid(size, List(size));

		for (int i = 0; i < size_; ++i)
			for (int j = 0; j < size_; ++j)
				adjacency_matrix[i][j] = 0;
	}

	bool full();
	bool empty();
	void addVertex(const int& vertex);
	int  findVertex(const int& vertex);
	List getAdjacencyList(const int& vertex);
	void setEdge(const int& start_vertex, const int& finish_vertex, const int& weight);
	void deleteEdge(const int& start_vertex, const int& finish_vertex);
	void deleteVertex(const int& vertex);
	void printAdjacencyMatrix();
	void simplePathfindingAlgoritm(const int& start_vertex);
};