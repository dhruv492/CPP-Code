#include <iostream>
using namespace std;

class SortedMerger
{
    int* mergedArray;
    int mergedSize;

    public:
        SortedMerger(int* arr1, int size1, int* arr2, int size2)
        {
            mergedSize = size1 + size2;
            mergedArray = new int[mergedSize];

            int i = 0, j = 0, k = 0;

        while (i < size1 && j < size2)
        {
            if (arr1[i] < arr2[j])
            {
                mergedArray[k++] = arr1[i++];
            }
            else
            {
                mergedArray[k++] = arr2[j++];
            }
        }

        while (i < size1)
        {
            mergedArray[k++] = arr1[i++];
        }

        while (j < size2)
        {
            mergedArray[k++] = arr2[j++];
        }
    }

    ~SortedMerger()
    {
        delete[] mergedArray;
    }

    void display() const
    {
        cout << "Merged Sorted Array: ";
        for (int i = 0; i < mergedSize; ++i)
        {
            cout << mergedArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < size1; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < size2; ++i)
    {
        cin >> arr2[i];
    }

    SortedMerger merger(arr1, size1, arr2, size2);
    merger.display();

    delete[] arr1;
    delete[] arr2;

    return 0;
}

