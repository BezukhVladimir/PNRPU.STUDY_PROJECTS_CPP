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
#include <iostream>

void linearSearch(const std::vector<int>& arr, std::vector<int>& result, const int& key)
{
    for (size_t i = 0; i != arr.size(); ++i)
        if (arr[i] == key)
            result.emplace_back(i);
}

void printVector(const std::vector<int>& arr)
{
    for (const auto& value : arr)
        std::cout << value << ' ';

    std::cout << '\n';
}

void printArray(const int* array, const size_t& size)
{
    for (size_t i = 0; i != size; ++i)
        std::cout << i << " <- индекс | значение -> " << array[i] << '\n';
}

int interpolationSearch(const int* array, const size_t& size, int key)
{
    int left = 0, right = static_cast<int>(size) - 1, middle;

    while (array[left] < key && key <= array[right])
    {
        middle = left + ((key - array[left])
            * (right - left)) / (array[right] - array[left]);

        if (array[middle] < key)
            left = middle + 1;
        else if (array[middle] > key)
            right = middle - 1;
        else
            return middle;
    }

    if (array[left] == key)
        return left;

    return -1; // value is not found 
}

void secondTask()
{
    const size_t size = 10;
    int array[size] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

    int key, index;
    std::cin >> key;

    printArray(array, size);

    index = interpolationSearch(array, size, key);

    if (index != -1)
        std::cout << "Значение " << key << " найдено по индексу " << index;
    else
        std::cout << "Значение не найдено :(";
}

void firstTask()
{
    std::vector<int> arr, result;
    for (int i = 0; i != 10; ++i)
        arr.emplace_back(i * i);

    for (int i = 0; i != 10; ++i)
        arr.emplace_back(i * i);

    printVector(arr);

    int key; std::cin >> key;
    linearSearch(arr, result, key);

    printVector(result);

    if (result.size())
        for (const auto& index : result)
            std::cout << "Ключ " << key << " находится по индексу " << index << ": " << arr[index] << '\n';
    else
        std::cout << "Ключ " << key << " не найден в массиве" << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");

    firstTask();
    secondTask();
}