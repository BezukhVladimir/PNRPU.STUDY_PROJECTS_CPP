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

/*
* Developed by Bezukh Vladimir
* ИВТ-21-2б
*/

#include <iostream>

int main()
{
	const int rows = 4, cols = 6;
	int first_array[rows][cols] = { {0, 1, 2, 3, 4, 5},
									{6, 7, 8, 9, 10, 11},
									{12, 13, 14, 15, 16, 17},
									{18, 19, 20, 21, 22, 23} };

	int second_array[2 * rows * cols] = { 6, 7, 8, 9, 10, 11,
										  0, 1, 2, 3, 4, 5,
										  18, 19, 20, 21, 22, 23,
										  12, 13, 14, 15, 16, 17,
										  2, 8, 14, 20,
										  5, 11, 17, 23,
										  0, 6, 12, 18,
										  3, 9, 15, 21,
										  1, 7, 13, 19,
										  4, 10, 16, 22 };

	int decoding_array[rows][cols];
	for (int col = 0; col != cols; ++col) {
		int row = 0;

		for (int i = rows * cols; i != 2 * rows * cols; ++i) {
			if (second_array[col] == second_array[i]) {
				for (int j = 0; j != rows; ++j)
					decoding_array[j][col] = second_array[i - row + j];

				break;
			}

			++row; if (row == rows) row = 0;
		}
	}

	for (int i = 0; i != rows; ++i) {
		for (int j = 0; j != cols; ++j)
			std::cout << decoding_array[i][j] << " ";

		std::cout << "\n";
	}
}