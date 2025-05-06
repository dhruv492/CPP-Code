#include <iostream>
using namespace std;

class DynamicArray
{
    int* data;
    int size;
    int capacity;

    void resize()
    {
        int new_capacity = capacity * 2;
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    public:
        DynamicArray(int cap = 2) : size(0), capacity(cap)
    {
        data = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            return;
        }
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
    }

    void display() const
    {
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.display();

    arr.remove(1);
    arr.display();

    return 0;
}

