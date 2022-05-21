#include "Graph.h"

bool Graph::full() {
	return vertices_.size() == size_;
}

bool Graph::empty() {
	return vertices_.empty();
}

void Graph::addVertex(const int& vertex)
{
	if (full()) {
		std::cout << "Нельзя добавить новую вершину: граф заполнен на максимум.\n";
		return;
	}

	vertices_.emplace_back(vertex);
}

int Graph::findVertex(const int& vertex)
{
	for (int i = 0; i < vertices_.size(); ++i)
		if (vertices_[i] == vertex)
			return i;

	return -1;
}

List Graph::getAdjacencyList(const int& vertex)
{
	List adjacency_list;
	int vertex_position = findVertex(vertex);

	if (vertex_position != -1)
		for (int i = 0; i < vertices_.size(); ++i)
			if (adjacency_matrix[vertex_position][i] != 0)
				adjacency_list.push_back(vertices_[i]);

	return adjacency_list;
}

void Graph::setEdge(const int& start_vertex,
					const int& finish_vertex,
					const int& weight) {
	int start_vertex_position = findVertex(start_vertex);
	int finish_vertex_position = findVertex(finish_vertex);

	if (start_vertex_position == -1 || finish_vertex_position == -1)
	{
		std::cout << "Как минимум одной из вершин нет в графе\n";
		return;
	}

	adjacency_matrix[start_vertex_position][finish_vertex_position] = weight;
	adjacency_matrix[finish_vertex_position][start_vertex_position] = weight;
}

void Graph::deleteEdge(const int& start_vertex,
				       const int& finish_vertex) {
	int start_vertex_position = findVertex(start_vertex);
	int finish_vertex_position = findVertex(finish_vertex);

	if (start_vertex_position == -1 || finish_vertex_position == -1)
	{
		std::cout << "Как минимум одной из вершин нет в графе\n";
		return;
	}

	adjacency_matrix[start_vertex_position][finish_vertex_position] = 0;
	adjacency_matrix[finish_vertex_position][start_vertex_position] = 0;
}

void Graph::deleteVertex(const int& vertex)
{
	List adjacency_list = getAdjacencyList(vertex);

	int vertex_position = findVertex(vertex);
	adjacency_matrix.erase(adjacency_matrix.begin() + vertex_position);

	for (int i = 0; i < adjacency_matrix.size(); ++i)
		adjacency_matrix[i].erase(adjacency_matrix[i].begin() + vertex_position);

	auto it = remove(vertices_.begin(), vertices_.end(), vertex);
	vertices_.erase(it, vertices_.end());
}

void Graph::printAdjacencyMatrix()
{
	if (empty()) {
		std::cout << "Граф пуст\n";
		return;
	}

	std::cout << "Матрица смежности: \n-   ";

	for (int i = 0; i < vertices_.size(); ++i)
		std::cout << vertices_[i] << "  ";

	std::cout << "\n";

	for (int i = 0; i < vertices_.size(); ++i)
	{
		std::cout << vertices_[i] << "  ";
		for (int j = 0; j < vertices_.size(); ++j)
			std::cout << " " << adjacency_matrix[i][j] << " ";

		std::cout << "\n";
	}
}

void Graph::simplePathfindingAlgoritm(const int& start_vertex)
{
	int start_vertex_position = findVertex(start_vertex);
	bool* isVisited = new bool[vertices_.size()];
	unsigned* distances = new unsigned[vertices_.size()];
	unsigned minimal_weight, minimal_index;

	for (unsigned i = 0; i < vertices_.size(); ++i)
	{
		isVisited[i] = false;
		distances[i] = std::numeric_limits<int>::max();
	}

	distances[start_vertex_position] = 0;

	do
	{
		minimal_index = std::numeric_limits<int>::max();
		minimal_weight = std::numeric_limits<int>::max();

		for (int i = 0; i < vertices_.size(); ++i)
			if (!isVisited[i] && distances[i] < minimal_weight)
			{
				minimal_index = i;
				minimal_weight = distances[i];
			}

		if (minimal_index != std::numeric_limits<int>::max())
		{
			for (int i = 0; i < vertices_.size(); ++i)
				if (adjacency_matrix[minimal_index][i])
				{
					int temp = minimal_weight + adjacency_matrix[minimal_index][i];

					if (temp < distances[i])
						distances[i] = temp;
				}

			isVisited[minimal_index] = true;
		}
	} while (minimal_index < std::numeric_limits<int>::max());

	for (int i = 0; i < vertices_.size(); ++i)
	{
		if (distances[i] != std::numeric_limits<int>::max())
		{
			std::cout << "Вес: " << vertices_[start_vertex_position]
				<< " ~> " << vertices_[i] << " =\t" << distances[i] << "\t";

			int end = i;
			int weight = distances[end];
			std::string path = std::to_string(vertices_[end]) + " >~ ";

			while (end != start_vertex_position)
				for (unsigned j = 0; j < vertices_.size(); ++j)
					if (adjacency_matrix[j][end])
					{
						int temp = weight - adjacency_matrix[j][end];

						if (temp == distances[j])
						{
							end = j;
							weight = temp;
							path += std::to_string(vertices_[j]) + " >~ ";
						}
					}

			std::cout << "Путь: ";

			for (int j = path.length() - 5; j >= 0; --j)
				std::cout << path[j];

			std::cout << "\n";
		}
		else
			std::cout << "Вес: " << vertices_[start_vertex_position]
			<< " ~ " << vertices_[i] << " = " << "маршрут недоступен\n";
	}

	delete[] isVisited;
	delete[] distances;
}