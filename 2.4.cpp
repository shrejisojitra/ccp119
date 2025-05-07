#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class InventoryItem {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default constructor
    InventoryItem() {
        itemID = 0;
        itemName = "N/A";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    InventoryItem(int id, string name, double pr, int qty) {
        itemID = id;
        itemName = name;
        price = pr;
        quantity = qty;
    }

    
    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
            cout << "Stock added: " << amount << " to item " << itemID << endl;
        } else {
            cout << "Invalid stock amount." << endl;
        }
    }

    
    bool sellItem(int amount) {
        if (amount <= 0) {
            cout << "Invalid sale amount." << endl;
            return false;
        } else if (amount > quantity) {
            cout << "Not enough stock to sell " << amount << " units of item " << itemID << "." << endl;
            return false;
        } else {
            quantity -= amount;
            cout << "Sold " << amount << " units of item " << itemID << "." << endl;
            return true;
        }
    }

   
    void displayItem() const {
        cout << "Item ID    : " << itemID << endl;
        cout << "Item Name  : " << itemName << endl;
        cout << "Price      : $" << price << endl;
        cout << "Quantity   : " << quantity << endl;
        cout << "---------------------------" << endl;
    }

    int getItemID() const {
        return itemID;
    }
};

int main() {
    InventoryItem items[MAX_ITEMS];
    int itemCount = 0;

    
    items[itemCount++] = InventoryItem(101, "T-shirt", 19.99, 50);
    items[itemCount++] = InventoryItem(102, "Jeans", 39.99, 30);
    items[itemCount++] = InventoryItem(103, "Sneakers", 59.99, 20);

    
    items[0].addStock(10);   
    items[1].addStock(5);     

   
    items[0].sellItem(20);    
    items[2].sellItem(25);    
    items[2].sellItem(5);    

    cout << "\n--- Inventory Summary ---\n";
    for (int i = 0; i < itemCount; i++) {
        items[i].displayItem();
    }

    return 0;
}
