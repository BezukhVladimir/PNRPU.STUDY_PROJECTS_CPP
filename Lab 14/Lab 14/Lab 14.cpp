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

void computeLPSArray(char* pattern, int pattern_length, int* longest_proper_suffix)
{
	int length = 0; longest_proper_suffix[0] = 0;

	int i = 1;
	while (i < pattern_length)
	{
		if (pattern[i] == pattern[length])
		{
			length++;
			longest_proper_suffix[i] = length;
			i++;
		}
		else // (pattern[i] != pattern[length])
		{
			if (length != 0)
				length = longest_proper_suffix[length - 1];
			else // if (length == 0)
			{
				longest_proper_suffix[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pattern, char* text)
{
	int pattern_length = strlen(pattern);
	int text_length = strlen(text);

	int* longest_proper_suffix = new int[pattern_length];
	computeLPSArray(pattern, pattern_length, longest_proper_suffix);

	int i = 0;
	int j = 0;
	while (i < text_length)
	{
		if (pattern[j] == text[i]) { j++; i++; }

		if (j == pattern_length)
		{
			std::cout << "Found pattern at index: " << i - j << '\n';
			j = longest_proper_suffix[j - 1];
		}
		else if (i < text_length && pattern[j] != text[i])
		{
			if (j != 0) j = longest_proper_suffix[j - 1];
			else i = i + 1;
		}
	}

	delete [] longest_proper_suffix;
}

int main()
{
	char text[] = "TENETENET ABCTENCD TEN ET AENET TENTEN";
	char first_pattern[] = "TEN", second_pattern[] = "TENET";
	KMPSearch(first_pattern, text);
	KMPSearch(second_pattern, text);
}