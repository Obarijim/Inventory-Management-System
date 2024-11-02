#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

std::string Item::getName() const {
	return name;
}

double Item::totalValue() {
	return price * quantity;
}

Item::Item(std::string name_val, double price_val, int quantity_val)
	: name( name_val ), price( price_val ), quantity( quantity_val ){

}

Item::~Item() {
	cout << "The Object is destroyed" << endl;
}

void Item::updateQuantity(int newQuantity) {
	quantity = newQuantity;
	cout << "New quantity: " << newQuantity << endl;
}


void Item::display() {
	cout << name << " " << price << " " << quantity << endl;
	cout << "Total: " << totalValue() << endl;
}
