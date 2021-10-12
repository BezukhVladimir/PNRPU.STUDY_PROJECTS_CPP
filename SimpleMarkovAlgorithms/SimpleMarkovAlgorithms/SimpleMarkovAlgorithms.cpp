/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/ 
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
* 
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
* 
* © Developed by Bezukh Vladimir. All right reserved.
*/

/*
* Developed by Bezukh Vladimir
* October 2021
* ИВТ-21-2б
*
* Консольное приложение для применения нормального алгоритма Маркова.
*/

#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

struct MarkovRule
{
	bool is_rule_terminal;
	string left_side_rule, right_side_rule;

	MarkovRule(string left_side_rule, bool is_rule_terminal, string right_side_rule) :
		left_side_rule(left_side_rule), is_rule_terminal(is_rule_terminal), right_side_rule(right_side_rule) {}
};

bool applyMarkovRule(string &word,
					 const MarkovRule &MARKOV_RULE)
{
	// поиск в обрабатываемом слове позиции первого вхождения под-слова из левой части правила
	unsigned int position = word.find(MARKOV_RULE.left_side_rule);

	if (position != string::npos) // если было найдено вхождение, то...
	{
		// заменяем найденное вхождение на правую часть правила, возвращаем успех
		word.replace(position, MARKOV_RULE.left_side_rule.length(), MARKOV_RULE.right_side_rule);
		return true;
	}

	return false; // если не применили правило, возвращаем неуспех
}

const string normalMarkovAlgorithm(const string &WORD,
								   const vector<MarkovRule> &MARKOV_RULES)
{
	string output_word = WORD;
	size_t step_counter = 0; // подсчёт количества шагов алгоритма
	bool is_terminal_flag = false; // флаг для терминального правила

	while (!is_terminal_flag) // до тех пор, пока не выполнилось терминальное правило...
	{
		size_t number_of_rule = 1; // счётчик для номера правила
		bool has_replacement_occured = false; // флаг об успешном применении правила

		for (const auto &MARKOV_RULE : MARKOV_RULES) // последовательно проходим по всем правилам
		{
			if (!is_terminal_flag) // если ранее не применялось терминальное правило, то...
			{
				++step_counter;

				has_replacement_occured =
					applyMarkovRule(output_word, MARKOV_RULE); // попробовать применить правило и сообщить результат

				// вывод подробной информации о состоянии слова после попытки применить правило
				cout << "Строка после применения правила №" << number_of_rule << ":\t"
					<< setiosflags(ios::left) << setw(20) << output_word
					<< resetiosflags(ios::left) << "\t(" << step_counter << " шаг)\n";

				if (has_replacement_occured) // если удалось применить правило, то...
				{
					// передать флагу терминальный статус ранее применённого правила
					is_terminal_flag = MARKOV_RULE.is_rule_terminal;
					break;
				}
			}
			else { break; } // если уже применили правило, выходим из цикла

			++number_of_rule; // переходим к следующему правилу
		}

		// если ни одно правило не было применено, завершаем алгоритм
		if (!has_replacement_occured)
			is_terminal_flag = true;
	}

	return output_word;
}

void normalMarkovAlgorithmTaskInterface(const vector<MarkovRule> &MARKOV_RULES)
{
	/* 
	* Запрашиваем строку INPUT_WORD у пользователя,
	* обрабатываем введённую строку INPUT_WORD по правилам нормального алгоритма Маркова MARKOV_RULES,
	* выводим результирующую строку OUTPUT_WORD.
	*/

	string INPUT_WORD; getline(cin, INPUT_WORD); cout << endl;

	const string OUTPUT_WORD =
		normalMarkovAlgorithm(INPUT_WORD, MARKOV_RULES);

	cout << endl << "Результирующая строка: " << OUTPUT_WORD << "\n\n";
}

void firstNormalMarkovAlgorithmTask()
{
	/*
	* Дано:
	* A = {a, b}.
	* Удалить из непустого произвольного слова P его первый символ.
	* Пустое слово не менять.
	* 
	* Решение:
	* *a |→
	* *b |→
	*  * |→
	*     → *
	*/

	const vector<MarkovRule> MARKOV_RULES = { MarkovRule("*a", true, ""),
											  MarkovRule("*b", true, ""),
											  MarkovRule("*", true, ""),
											  MarkovRule("", false, "*") };
		
	cout << "Введите строку для первого задания (A = {a, b}): ";
	normalMarkovAlgorithmTaskInterface(MARKOV_RULES);
}

void secondNormalMarkovAlgorithmTask()
{
	/*
	* Дано:
	* A = {a, b, c, d}.
	* В произвольном слове P требуется удалить все вхождения символа c,
	* затем заменить первое вхождение подслова bb на ddd.
	*
	* Решение:
	*  c  →
	* bb |→ ddd
	*/

	const vector<MarkovRule> MARKOV_RULES = { MarkovRule("c", false, ""),
											  MarkovRule("bb", true, "ddd") };

	cout << "Введите строку для второго задания (A = {a, b, c, d}): ";
	normalMarkovAlgorithmTaskInterface(MARKOV_RULES);
}

void thirdNormalMarkovAlgorithmTask()
{
	/*
	* Дано:
	* A = {a, b}.
	* Требуется приписать символ a к концу произвольного слова P.
	*
	* Решение:
	* *a  → a*
	* *b  → b*
	*  * |→ a
	*     → *
	*/

	const vector<MarkovRule> MARKOV_RULES = { MarkovRule("*a", false, "a*"),
											  MarkovRule("*b", false, "b*"),
											  MarkovRule("*", true, "a"),
											  MarkovRule("", false, "*") };

	cout << "Введите строку для третьего задания (A = {a, b}): ";
	normalMarkovAlgorithmTaskInterface(MARKOV_RULES);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	firstNormalMarkovAlgorithmTask();
	secondNormalMarkovAlgorithmTask();
	thirdNormalMarkovAlgorithmTask();
}