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

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string word;
    std::vector<std::string> words;

    char c;
    bool flag_correct_word = false, flag_first_element = false;
    while (std::cin.get(c)) {
        if (c == '.') break;

        if (c == '\n') {
            if (word.length() != 0)
                words.emplace_back(std::string(word));
                
            break;
        }

        if (c == ' ') {
            if (word.length() != 0) {
                words.emplace_back(std::string(word));
                word.clear();
            }

            flag_first_element = false;
            continue;
        }

        if (flag_first_element == false) {
            if (isalpha(c)) {
                word.push_back(c);
                flag_correct_word = true;
            }
            else
                flag_correct_word = false;

            flag_first_element = true;
            continue;
        }

        if (flag_correct_word)
            word.push_back(c);
    }

    for (auto word : words)
        std::cout << word << " ";

    std::cout << '\n';

    sort(words.begin(), words.end());

    for (auto word : words)
        std::cout << word << " ";
}