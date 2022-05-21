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

#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>

int main()
{
    std::vector<std::vector<std::string>> strings;
    std::ifstream f_input("FileInput.txt");
    std::ofstream f_output("FileOutput.txt");

    // input
    while (!f_input.eof()) {
        std::string word, temp;
        std::vector<std::string> words;

        getline(f_input, temp);
        std::stringstream string(temp);

        while (string >> word)
            words.emplace_back(word);
        
        strings.emplace_back(words);
    }

    // first task
    std::vector<std::vector<std::string>> firstTaskResult;
    for (const auto& words : strings) {
        std::vector<std::string> temp = words;
        std::sort(temp.begin(), temp.end());

        bool flag_two_equal_words = false;
        auto it = temp.begin(); std::string prev_word = *it; ++it;
        while (it != temp.end()) {
            if (prev_word == *it) {
                if (!flag_two_equal_words)
                    flag_two_equal_words = true;
                else {
                    flag_two_equal_words = false;
                    break;
                }
            }
            
            prev_word = *it;
            ++it;
        }

        if (flag_two_equal_words)
            firstTaskResult.emplace_back(words);
    }

    for (const auto& words : firstTaskResult) {
        for (const auto& word : words)
            f_output << word << ' ';

        f_output << '\n';
    }

    // second task
    size_t max = 0, max_number = 1, current_number = 1;
    for (const auto& words : strings) {
        for (const auto& word : words) {
            size_t counter = 0;
            for (const auto& symbol : word)
                if (symbol == 'a')
                    ++counter;

            if (counter > max)
            {
                max = counter;
                max_number = current_number;
            }

            ++current_number;
        }
    }

    f_output << max_number;

    f_input.close();
    f_output.close();
}