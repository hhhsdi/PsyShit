#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Shop.h"
#include <vector>

class Customer {
public:
    std::string name;
    double balance;
    std::vector<std::string> shoppingList;

    Customer(std::string n, double b);
    bool purchase(Shop& shop, std::string productName, int quantity);
    void displayBalance();
};

#endif