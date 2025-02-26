#include <iostream>
#include <vector>
#include "Shop.h"
#include "Customer.h"

void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить магазин\n";
    std::cout << "2. Добавить товар в магазин\n";
    std::cout << "3. Покупка товара\n";
    std::cout << "4. Вывести баланс покупателя\n";
    std::cout << "5. Найти магазин с самой низкой ценой\n";
    std::cout << "6. Вывести товары в магазинах\n";
    std::cout << "0. Выход\n";
}

int main() {
    std::setlocale(LC_ALL,"rus");
    std::vector<Shop> shops;
    Customer customer("Иван", 100.0);

    int choice;
    do {
        displayMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string shopName;
            std::cout << "Введите название магазина: ";
            std::cin >> shopName;
            shops.emplace_back(shopName);
        }
        else if (choice == 2) {
            std::string shopName, productName;
            double price;
            int quantity;
            std::cout << "Введите название магазина: ";
            std::cin >> shopName;
            std::cout << "Введите название товара: ";
            std::cin >> productName;
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            for (auto& shop : shops) {
                if (shop.name == shopName) {
                    shop.addProduct(productName, price, quantity);
                    break;
                }
            }
        }
        else if (choice == 3) {
            std::string shopName, productName;
            int quantity;
            std::cout << "Введите магазин: ";
            std::cin >> shopName;
            std::cout << "Введите товар: ";
            std::cin >> productName;
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            for (auto& shop : shops) {
                if (shop.name == shopName) {
                    customer.purchase(shop, productName, quantity);
                    break;
                }
            }
        }
        else if (choice == 4) {
            customer.displayBalance();
        }
        else if (choice == 6) {
            for (auto& shop : shops) {
                shop.displayProducts();
            }
        }
    } while (choice != 0);
    return 0;
}
