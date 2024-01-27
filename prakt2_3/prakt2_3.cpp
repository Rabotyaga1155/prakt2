#include <iostream>
#include <string>

struct House {
    char address[100]; 
    int bedrooms;      
    double price;      
};

double averagePrice(const House houses[], int size, int targetBedrooms) {
    double total = 0.0;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (houses[i].bedrooms == targetBedrooms) {
            total += houses[i].price;
            count++;
        }
    }

    if (count == 0) {
        std::cout << "Нет домов с " << targetBedrooms << " спальнями." << std::endl;
        return 0.0;
    }

    return total / count;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    House houses[4] = {
        {"123 Main St", 3, 250000.0},
        {"456 Elm St", 4, 320000.0},
        {"789 Oak St", 3, 270000.0},
        {"101 Pine St", 4, 350000.0}
    };

    int targetBedrooms;
    std::cout << "Введите количество спален для поиска средней цены: ";
    std::cin >> targetBedrooms;

    double avgPrice = averagePrice(houses, 4, targetBedrooms);
    if (avgPrice > 0.0) {
        std::cout << "Средняя цена для домов с " << targetBedrooms << " спальнями: $" << avgPrice << std::endl;
    }

    return 0;
}
