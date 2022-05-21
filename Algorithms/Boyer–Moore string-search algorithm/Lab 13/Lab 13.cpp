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
* Алгоритм Бойера — Мура
* Developed by Bezukh Vladimir
* ИВТ-21-2б
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

// good suffix heuristic
std::vector<int> prefix_func(const std::string& text) 
{
	std::vector<int> prefix(text.length());

	int k = 0; prefix[0] = 0;
	for (int i = 1; i != text.length(); ++i) 
	{
		while (k > 0 && text[k] != text[i])
			k = prefix[k - 1];

		if (text[k] == text[i]) 
			++k;

		prefix[i] = k;
	}

	return prefix;
}

std::vector<int> find(std::string& text, std::string& pattern) 
{
	if (text.length() < pattern.length())
		return std::vector<int>(1, -1);

	if (!pattern.length())
		return std::vector<int>(1, text.length());

	typedef std::unordered_map<char, int> TStopTable;
	typedef std::unordered_map<int, int> TSufficsTable;
	
	TStopTable stop_table;
	TSufficsTable suffics_table;

	// bad character heuristic
	for (int i = 0; i != static_cast<int>(pattern.length()); ++i)
		stop_table[pattern[i]] = i;

	std::string reverse_pattern(pattern.rbegin(), pattern.rend());
	std::vector<int> prefix = prefix_func(pattern), reverse_prefix = prefix_func(reverse_pattern);
	for (int i = 0; i != pattern.length() + 1; ++i)
		suffics_table[i] = pattern.length() - prefix.back();

	for (int i = 1; i != pattern.length(); ++i) {
		int j = reverse_prefix[i];
		suffics_table[j] = std::min(suffics_table[j], i - reverse_prefix[i] + 1);
	}

	std::vector<int> shifts;
	for (int shift = 0; shift <= static_cast<int>(text.length()) - static_cast<int>(pattern.length());)
	{
		int position = pattern.length() - 1;

		while (pattern[position] == text[position + shift]) {
			if (position == 0) { shifts.emplace_back(shift); break; }
			--position;
		}

		if (position == pattern.length() - 1) {
			TStopTable::const_iterator stop_symbol = stop_table.find(text[position + shift]);
			int stop_symbol_additional = position - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
			shift += stop_symbol_additional;
		} else shift += suffics_table[pattern.length() - 1 - position];
	}

	if (!shifts.empty())
		return shifts;

	return std::vector<int>(1, -1);
}

int main()
{
	std::string text = "TENETENET ABCTENCD TEN ET AENET TENTEN";
	std::string first_pattern = "TEN", second_pattern = "TENET";
	
	std::cout << "Text: " << text << std::endl;

	std::cout << "First pattern: " << first_pattern << std::endl;
	std::vector<int> shifts = find(text, first_pattern);
	for (const auto& shift : shifts)
		std::cout << "Shift: " << shift << std::endl;

	std::cout << "Second pattern: " << second_pattern << std::endl;
	shifts = find(text, second_pattern);
	for (const auto& shift : shifts)
		std::cout << "Shift: " << shift << std::endl;
}