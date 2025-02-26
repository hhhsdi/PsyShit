#pragma once
#include<iostream>
#include<vector>
#include "Product.h"
using namespace std;

class Shop {
	vector <Product> products;
	string title;
	int id;

public:
	Shop(string title, int id) : title(title), id(id) {};

	void addProduct(string& product_name, double price, int count);
	bool check_product(string& productName);
	string getName();
};