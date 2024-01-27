#include <iostream>

int main()
{
        setlocale(LC_ALL, "rus");

        int arr[] = { 1, -8, 3, -4, 5 }; 
        int size = sizeof(arr) / sizeof(arr[0]);
        int sum = 0;

        for (int i = 0; i < size; ++i) {
            sum += (arr[i] < 0) ? -arr[i] : arr[i];
        }

        std::cout << "Сумма абсолютных значений всех элементов массива: " << sum << std::endl;

        return 0;
}
