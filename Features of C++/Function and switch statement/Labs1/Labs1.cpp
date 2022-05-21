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
* November 2021
* ИВТ-21-2б
* 
* Лабораторная №1, вариант 2:
* 1. Вычислить значение выражения при различных вещественных
* типах данных (float и double). Вычисления следует
* выполнять с использованием промежуточных переменных.
* Сравнить и объяснить полученные результаты.
* 2. Вычислить значения выражений. Объяснить полученные
* результаты.
* 
* Задания:
* 1. Напишите программу для вывода всех последующих цифр начиная с
* введенной с клавиатуры.
* 2. Написать программу, которая складывает, вычитает, умножает,
* делит два числа введенных с клавиатуры. С пользовательским интерфейсом. 
*/

#include <iomanip>
#include <iostream>

using namespace std;

template <typename T> 
void function(const T &a, const T &b)
{
	T t_1, t_2, t_3, t_4, result;

	t_1 = (a - b) * (a - b);	cout << t_1 << "\n";
	t_2 = a * a - 2 * a * b;	cout << t_2 << "\n";
	t_3 = t_1 - t_2;			cout << t_3 << "\n";
	t_4 = b * b;				cout << t_4 << "\n";
	result =  t_3 / t_4;		cout << result << "\n\n";
}

void firstTask()
{
	int n = 1, m = 1;

	cout << (++n * ++m) << "\n";
	cout << (m++ < n) << "\n";
	cout << (n++ > m) << "\n\n";
}

void secondTask()	
{
	cout << "Введите цифру: ";
	int N; cin >> N;

	switch (N)
	{
	case 0:
		cout << "0 ";
	case 1:
		cout << "1 ";
	case 2:
		cout << "2 ";
	case 3:
		cout << "3 ";
	case 4:
		cout << "4 ";
	case 5:
		cout << "5 ";
	case 6:
		cout << "6 ";
	case 7:
		cout << "7 ";
	case 8:
		cout << "8 ";
	case 9:
		cout << "9\n\n";
	}
}

void thirdTask()
{
	cout << "Введите элементарную (+, -, *, /) бинарную арифметическую операцию в формате \"21.5 + 42\": ";

	char operation;
	double first_operand, second_operand;

	cin >> first_operand >> operation >> second_operand;
	cout << first_operand << " " << operation << " " << second_operand << " = ";

	switch (operation)
	{
	case '+':
		cout << first_operand + second_operand;
		break;
	case '-':
		cout << first_operand - second_operand;
		break;
	case '*':
		cout << first_operand * second_operand;
		break;
	case '/':
		cout << first_operand / second_operand;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << setprecision(12);
	
	const float A_F = 1000, B_F = 0.0001;
	function(A_F, B_F);
	
	const double A_D = 1000, B_D = 0.0001;
	function(A_D, B_D);

	firstTask();
	secondTask();
	thirdTask();
}	