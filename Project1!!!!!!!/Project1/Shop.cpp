#include "Shop.h"
#include <iostream>

Shop::Shop(std::string n) : name(n) {}

void Shop::addProduct(std::string name, double price, int quantity) {
    products.push_back(Product(name, price, quantity));
}

double Shop::getProductPrice(std::string productName) {
    for (const auto& product : products) {
        if (product.name == productName) {
            return product.price;
        }
    }
    return std::numeric_limits<double>::max();
}

void Shop::displayProducts() {
    std::cout << "Товары в " << name << ":\n";
    for (const auto& product : products) {
        std::cout << "- " << product.name << ", Цена: " << product.price << ", Количество: " << product.quantity << "\n";
    }
}
