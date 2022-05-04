#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
typedef std::vector<std::vector<double>> Matrix;

void branchAndBoundMethod(Matrix& mat, int n, Matrix& temp, std::vector<int>& route)
{
	for (int l = 0; l < n; ++l) {
		for (int i = 0; i < n; ++i) {
			int min = numeric_limits<int>::max();

			for (int j = 0; j < n; ++j)
				if (mat[i][j] && min > mat[i][j])
					min = mat[i][j];

			for (int j = 0; j < n; ++j)
				if (mat[i][j])
					mat[i][j] -= min;
		}

		for (int j = 0; j < n; ++j)
		{
			int min = numeric_limits<int>::max();

			for (int i = 0; i < n; ++i)
				if (mat[i][j] && min > mat[i][j])
					min = mat[i][j];

			for (int i = 0; i < n; ++i)
				if (mat[i][j])
					mat[i][j] -= min;
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				temp[i][j] = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] && !mat[i][j]) {
					int hmin = numeric_limits<int>::max();
					int vmin = numeric_limits<int>::max();

					for (int l = 0; l < n; ++l)
						if (l != i && mat[l][j] && hmin > mat[l][j])
							hmin = mat[l][j];

					for (int l = 0; l < n; ++l)
						if (l != j && mat[i][l] && vmin > mat[i][l])
							vmin = mat[i][l];

					temp[i][j] = hmin + vmin;
				}
			}

		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (mat[i][j] && mcost < temp[i][j]) {
					mcost = temp[i][j];
					mi = i;
					mj = j;
				}

		route[mi] = mj;

		for (int i = 0; i < n; ++i)
			mat[i][mj] = 0;

		for (int i = 0; i < n; ++i)
			mat[mi][i] = 0;

		mat[mj][mi] = 0;
	}
}