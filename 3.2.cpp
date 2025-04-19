#include <iostream>
using namespace std;

class ArraySum
{
    int* arr;
    int size;

    public:
        ArraySum(int n)
        {
            size = n;
            arr = new int[size];
        }

    ~ArraySum()
    {
        delete[] arr;
    }

    void inputElements()
    {
        cout << "Enter elements in array:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    int sumRecursive(int n) 
    {
        if (n <= 0)
            return 0;
        return arr[n - 1] + sumRecursive(n - 1);
    }

    int sumIterative()
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    void showSums() 
    {
        cout << "\nSum of all elements by recursive function: " << sumRecursive(size);
        cout << "\nSum of all elements by iterative function: " << sumIterative();
    }
};

int main() 
{
    int n;
    cout << "\nEnter number of elements of integer array: ";
    cin >> n;

    ArraySum obj(n);
    obj.inputElements();
    obj.showSums();

    return 0;
}
