#pragma once
#include<iostream>
#include<map>
#include"Product.h"
using namespace std;
class Buyer {
	int id;
	string name;
	double money;
	map<Product, int> productList;
public:
	Buyer(string name, int id, double money) : name(name), id(id), money(money) {};
};