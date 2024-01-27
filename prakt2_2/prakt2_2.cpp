#include <iostream>



    bool isElementsUnique(int arr[3][3], int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols - 1; ++j) {
                for (int k = j + 1; k < cols; ++k) {
                    if (arr[i][j] == arr[i][k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    int main() {
        setlocale(LC_ALL, "rus");
        int arr[3][3] = {       {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 8} };

        if (isElementsUnique(arr, 3, 3)) {
            std::cout << "Все элементы в каждой строке уникальны." << std::endl;
        }
        else {
            std::cout << "Есть повторяющиеся элементы в строках массива." << std::endl;
        }

        return 0;
    }





