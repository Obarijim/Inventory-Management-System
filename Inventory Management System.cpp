#include "Item.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

void add_item(vector <Item*> &inventory) {
    std::string name;
    double price;
    int quantity;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "How much is the object: ";
    cin >> price;
    cout << "How many objects: ";
    cin >> quantity;

    Item* newItem = new Item(name, price, quantity);
    inventory.push_back(newItem);
    cout << "Item added" << endl;

}

void update_Item_quantity(vector <Item*>& inventory) {
    std::string name;
    int new_quantity;
    bool found = false;

    cout << "Enter item name you want to update:";
    cin >> name;

    for (auto& item : inventory) {
        if (item->getName() == name) {
            cout << "Enter new name: ";
            cin >> new_quantity;
            item->updateQuantity(new_quantity);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Item not found" <<endl;

}

void displayInventory(const vector<Item*>& inventory) {
    cout << "Inventory:" << endl;
    if (inventory.empty()) {
        cout << "No items in inventory." << endl;
        return;
    }

    int index = 1;
    for (const auto& item : inventory) {
        cout << index << ". ";
        item->display();
        index++;
    }
}

double calculateTotalInventoryValue(const vector<Item*>& inventory) {
    double total = 0;
    for (const auto& item : inventory) {
        total += item->totalValue();
    }
    return total;
}


int main()
{
    vector <Item*> Inventory;
    int choice;
    do {
        cout << "\n1. Add Item" << endl;
        cout << "2. Update Quantity" << endl;
        cout << "3. Display Inventory" << endl;
        cout << "4. Calculate Total Inventory Value" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

            switch (choice) {
            case 1:
                add_item(Inventory);
                break;
            case 2:
                update_Item_quantity(Inventory);
                break;
            case 3:
                displayInventory(Inventory);
                break;
            case 4:
                calculateTotalInventoryValue(Inventory);
                break;
            case 5:
                cout << "You are now exiting the program\n" << endl;
                break;
            default:
                cout << "Incorrect input.\n" <<endl;
            }
    } while (choice != 5);

    for (auto& item : Inventory) {
        delete item;
    }

    return 0;
}

