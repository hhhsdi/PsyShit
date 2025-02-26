#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include "Product.h"

class Shop {
public:
    std::string name;
    std::vector<Product> products;

    Shop(std::string n);
    void addProduct(std::string name, double price, int quantity);
    double getProductPrice(std::string productName);
    void displayProducts();
};
#endif