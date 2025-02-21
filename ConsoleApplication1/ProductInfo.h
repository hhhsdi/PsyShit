#pragma once
#include<iostream>
#include<vector>
#include "Product.h"
using namespace std;

class ProductInfo {
    Product product;
    double price;
    int quantity;
public:
    Product(double price, int quantity) : quantity(quantity), price(price) {};

};