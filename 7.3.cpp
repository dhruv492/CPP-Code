#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class InventoryManager
{
private:
    struct Item
    {
        char name[50];
        int quantity;
        float price;
    };

    const char* filename;

public:
    InventoryManager(const char* file) : filename(file) {}

    void addItem()
    {
        ofstream file(filename, ios::app | ios::binary);
        if (!file)
        {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        Item item;
        cout << "Enter item name: ";
        cin.ignore();
        cin.getline(item.name, 50);
        cout << "Enter quantity: ";
        cin >> item.quantity;
        cout << "Enter price: ";
        cin >> item.price;

        file.write(reinterpret_cast<char*>(&item), sizeof(Item));
        file.close();
    }

    void viewInventory()
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error: Unable to open file for reading." << endl;
            return;
        }

        Item item;
        cout << "\nInventory List:\n";
        while (file.read(reinterpret_cast<char*>(&item), sizeof(Item)))
        {
            cout << "Name: " << item.name << ", Quantity: " << item.quantity
                 << ", Price: " << item.price << endl;
        }
        file.close();
    }

    void searchItem()
    {
        ifstream file(filename, ios::binary);
        if (!file)
        {
            cout << "Error: Unable to open file for searching." << endl;
            return;
        }

        char searchName[50];
        cout << "Enter item name to search: ";
        cin.ignore();
        cin.getline(searchName, 50);

        Item item;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&item), sizeof(Item)))
        {
            if (strcmp(item.name, searchName) == 0)
            {
                cout << "Item Found - Name: " << item.name << ", Quantity: " << item.quantity
                     << ", Price: " << item.price << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Item not found." << endl;
        }

        file.close();
    }
};

int main()
{
    InventoryManager manager("inventory.dat");
    int choice;
    do
    {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                manager.addItem();
                break;
            case 2:
                manager.viewInventory();
                break;
            case 3:
                manager.searchItem();
                break;
            case 4:
                cout << "You are Exited." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    while (choice != 4);

    return 0;
}
