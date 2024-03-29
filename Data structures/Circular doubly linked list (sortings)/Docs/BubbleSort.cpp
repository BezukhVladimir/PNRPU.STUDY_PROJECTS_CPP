#include <iostream>

using namespace std;

template<typename T>
void bubbleSort(T *a, size_t size)
{
    for(size_t i = 0; i != size; ++i)
        for(size_t j = size - 1; j > i; --j)
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
}

int main()
{
    size_t n; cin >> n;
 
    int *array = new int[n];

    for (size_t i = 0; i != n; ++i)
        cin >> array[i];
        
    bubbleSort(array, n);
    
    for (size_t i = 0; i != n; ++i)
        cout << array[i] << ' ';

    return 0;
}
