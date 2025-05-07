#include <iostream>
 #include <string>
 using namespace std;

 class Product {
 private:
     int productID;
     string productName;
     int quantity;
     double pricePerUnit;

 public:
     Product(int id = 0, string name = "", int qty = 0, double price = 0.0) {
         productID = id;
         productName = name;
         quantity = qty;
         pricePerUnit = price;
     }

     int getProductID() const { return productID; }
     string getProductName() const { return productName; }
     int getQuantity() const { return quantity; }
     double getPricePerUnit() const { return pricePerUnit; }

     void setQuantity(int qty) { quantity = qty; }

     void displayProduct() const {
         cout << "Product ID: " << productID << ", Name: " << productName
              << ", Quantity: " << quantity << ", Price per unit: $" << pricePerUnit << endl;
     }

     double getTotalValue() const {
         return quantity * pricePerUnit;
     }
 };

 class Inventory {
 private:
     Product products[100];
     int productCount;
 public:
     Inventory() {
         productCount = 0;
     }
     void addProduct(int id, string name, int qty, double price) {
         if (productCount < 100) {
             products[productCount] = Product(id, name, qty, price);
             productCount++;
             cout << "Product added successfully: " << name << endl;
         } else {
             cout << "Inventory is full. Cannot add more products." << endl;
         }
     }
     void updateQuantity(int productID, int qty) {
         for (int i = 0; i < productCount; i++) {
             if (products[i].getProductID() == productID) {
                 products[i].setQuantity(qty);
                 cout << "Quantity updated for product: " << products[i].getProductName() << endl;
                 return;
             }
         }
         cout << "Product not found with ID: " << productID << endl;
     }
     void displayInventoryTotalValue() const {
         double totalValue = 0;
         for (int i = 0; i < productCount; i++) {
             totalValue += products[i].getTotalValue();
         }
         cout << "Total value of inventory: $" << totalValue << endl;
     }
     void displayAllProducts() const {
         if (productCount == 0) {
             cout << "No products in the inventory." << endl;
         } else {
             for (int i = 0; i < productCount; i++) {
                 products[i].displayProduct();
             }
         }
     }
 };

 int main() {
     Inventory storeInventory;
     storeInventory.addProduct(1, "Laptop", 10, 800.00);
     storeInventory.addProduct(2, "Smartphone", 15, 500.00);
     storeInventory.addProduct(3, "Headphones", 50, 20.00);
     cout << "\nAll Products in Inventory:\n";
     storeInventory.displayAllProducts();
     cout << "\nUpdating quantity of product with ID 1 (Laptop) to 12...\n";
     storeInventory.updateQuantity(1, 12);
     cout << "\nUpdated Inventory:\n";
     storeInventory.displayAllProducts();
     storeInventory.displayInventoryTotalValue();
     return 0;
 }
