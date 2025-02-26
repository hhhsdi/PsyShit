#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product {
public:
    std::string name;
    double price;
    int quantity;

    Product(std::string n, double p, int q);
};

#endif