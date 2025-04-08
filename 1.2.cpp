#include <iostream>
using namespace std;

class Product
{
    int productID;
    char productName[50];
    int quantity;
    double price;

public:
    Product(int id = 0, const char* name = "", int qty = 0, double prc = 0.0) : productID(id), quantity(qty), price(prc)
    {
        int i;
        for (i = 0; i < 49 && name[i] != '\0'; ++i)
        {
            productName[i] = name[i];
        }
        productName[i] = '\0';
    }

    void updateQuantity(int qty)
    {
        quantity += qty;
    }

    double calculateValue() const
    {
        return quantity * price;
    }

    void displayProductDetails() const
    {
        cout << "Product ID: " << productID << ", Name: " << productName
             << ", Quantity: " << quantity << ", Price: " << price
             << ", Value: " << calculateValue() << endl;
    }

    int getProductID() const {
        return productID;
    }
};

class Inventory
{
    Product products[10];
    int productCount;

public:
    Inventory() : productCount(0) {}

    void addProduct(int id, const char* name, int qty, double price)
    {
        if (productCount < 10)
        {
            products[productCount++] = Product(id, name, qty, price);
            cout << "Product added successfully." << endl;
        }
        else
        {
            cout << "Inventory full. Cannot add more products." << endl;
        }
    }

    void updateProductQuantity(int id, int qty)
    {
        for (int i = 0; i < productCount; ++i)
        {
            if (products[i].getProductID() == id)
            {
                products[i].updateQuantity(qty);
                cout << "Updated product with ID: " << id << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    double calculateTotalInventoryValue() const
    {
        double totalValue = 0.0;
        for (int i = 0; i < productCount; ++i)
        {
            totalValue += products[i].calculateValue();
        }
        return totalValue;
    }

    void displayAllProducts() const
    {
        cout << "Inventory Details:\n";
        for (int i = 0; i < productCount; ++i)
        {
            products[i].displayProductDetails();
        }
    }
};

int main()
{
    Inventory i;

    i.addProduct(101, "Apples", 50, 1.20);
    i.addProduct(102, "Bananas", 30, 0.80);
    i.addProduct(103, "Oranges", 40, 1.50);

    i.displayAllProducts();

    i.updateProductQuantity(101, 20);
    i.updateProductQuantity(102, -10);

    i.displayAllProducts();

    double totalValue = i.calculateTotalInventoryValue();
    cout << "Total Inventory Value: " << totalValue << endl;

    return 0;
}
