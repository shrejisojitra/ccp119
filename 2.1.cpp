#include <iostream>
 #include <string>
 using namespace std;
 class Rectangle {
 private:
     double length;
     double width;
 
 public:
     Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
     double getLength() const { return length; }
     double getWidth() const { return width; }
     
     void setLength(double l) { length = l; }
     void setWidth(double w) { width = w; }
     double calculateArea() const {
         return length * width;
     }
     double calculatePerimeter() const {
         return 2 * (length + width);
     }
     void displayDetails() const {
         cout << "Length: " << length << ", Width: " << width
              << ", Area: " << calculateArea() 
              << ", Perimeter: " << calculatePerimeter() << endl;
     }
 };
 class RectangleManager {
 private:
     Rectangle rectangles[100]; 
     int rectangleCount; 
 
 public:
     RectangleManager() : rectangleCount(0) {}
     void addRectangle(double length, double width) {
         if (rectangleCount < 100) {
             rectangles[rectangleCount] = Rectangle(length, width);
             rectangleCount++;
             cout << "Rectangle added successfully!" << endl;
         } else {
             cout << "Cannot add more rectangles. Limit reached." << endl;
         }
     }
     void updateRectangle(int index, double length, double width) {
         if (index >= 0 && index < rectangleCount) {
             rectangles[index].setLength(length);
             rectangles[index].setWidth(width);
             cout << "Rectangle updated successfully!" << endl;
         } else {
             cout << "Invalid index. Rectangle not found." << endl;
         }
     }
     void displayAllRectangles() const {
         if (rectangleCount == 0) {
             cout << "No rectangles available." << endl;
         } else {
             for (int i = 0; i < rectangleCount; i++) {
                 cout << "Rectangle " << i + 1 << ": ";
                 rectangles[i].displayDetails();
             }
         }
     }
 };
 
 int main() {
     RectangleManager manager;
     manager.addRectangle(5.0, 3.0); // Rectangle 1
     manager.addRectangle(10.0, 2.5); // Rectangle 2
     manager.addRectangle(7.0, 8.0);  // Rectangle 3
     cout << "\nDisplaying all rectangles:" << endl;
     manager.displayAllRectangles();
     cout << "\nUpdating Rectangle 1 dimensions..." << endl;
     manager.updateRectangle(0, 6.0, 4.0); 
     cout << "\nDisplaying updated rectangles:" << endl;
     manager.displayAllRectangles();
     return 0;
 }
