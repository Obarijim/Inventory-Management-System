#pragma once

#include <string>

class Item {
private:
	std::string name;
	double price;
	int quantity;

public:
	Item(std::string name_val, double price_val, int quantity_val);
	~Item();

	std::string getName() const;
	double totalValue();
	void updateQuantity(int newQuantity);
	void display();
};