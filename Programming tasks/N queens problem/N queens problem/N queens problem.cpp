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

int counter = 0;
const int N = 8;

bool rows[N];
bool cols[N];
bool main_diagonals[2 * N - 1];
bool anti_diagonals[2 * N - 1];

bool board[N][N];

void printResult()
{
    for (int row = 0; row != N; ++row) {
        for (int col = 0; col != N; ++col)
            std::cout << (board[row][col] ? "Q " : "X ");

        std::cout << "\n";
    }

    std::cout << "\n";
    ++counter;
}

bool isSafe(const int& row, const int& col)
{
    return !(rows[row] || cols[col] || main_diagonals[col - row + N - 1] || anti_diagonals[col + row]);
}

void solve(const int& row) {
    if (N == row) {
        printResult();
        return;
    }

    for (int col = 0; col != N; ++col) {
        if (isSafe(row, col)) {
            board[row][col] = true;
            rows[row] = cols[col] = main_diagonals[col - row + N - 1] = anti_diagonals[col + row] = true;

            solve(row + 1);

            board[row][col] = false;
            cols[col] = rows[row] = main_diagonals[col - row + N - 1] = anti_diagonals[col + row] = false;
        }
    }
}

int main()
{
    solve(0);

    if (!counter) std::cout << "Solutions do not exist!\n";
    else std::cout << "Total solutions: " << counter;
}