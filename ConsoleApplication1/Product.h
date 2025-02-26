
#define CHARACTER_H
#include<string>
#include <iostream>
using namespace std;
class Product {
    string title;
    int id = 0;
public:
    Product(double price, int count, string name_product) : price(price), count(count), name_product(name_product) {};

    double getPrice();
    int getCount();
    int getId();
    string getNameProduct();
};