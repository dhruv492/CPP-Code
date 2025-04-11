#include <iostream>
using namespace std;

template <typename Type>
class Collection
{
    int NumElements;
    Type* Kollection;

public:
    Collection() : NumElements(0), Kollection(0) {} // Initialized Kollection to 0 instead of nullptr

    void InputCollection()
    {
        if (NumElements != 0)
        {
            cout << "\nThis Collection already exists.";
            return;
        }

        cout << "\nEnter the number of elements in this Collection: ";
        cin >> NumElements;

        if (NumElements <= 0)
        {
            cout << "\nInvalid number of elements!";
            return;
        }

        Kollection = new Type[NumElements];

        cout << "\nEnter all elements of this collection:\n";
        for (int i = 0; i < NumElements; i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> Kollection[i];
        }
        cout << "\nNew Collection Added Successfully!";
    }

    void Display() const
    {
        if (NumElements == 0 || Kollection == 0) // Checking against 0 instead of nullptr
        {
            cout << "\nCollection is empty.";
            return;
        }

        cout << "\nDisplaying collection:";
        for (int i = 0; i < NumElements; i++)
        {
            cout << "\nElement " << i + 1 << ": " << Kollection[i];
        }
    }

    void Reverse()
    {
        if (NumElements == 0 || Kollection == 0)
        {
            cout << "\nCollection is empty.";
            return;
        }

        for (int j = 0; j < NumElements / 2; j++)
        {
            Type temp = Kollection[j];
            Kollection[j] = Kollection[NumElements - j - 1];
            Kollection[NumElements - j - 1] = temp;
        }

        cout << "\nElements reversed successfully!";
        Display();
    }

    Type FindMax() const
    {
        if (NumElements == 0 || Kollection == 0)
        {
            cout << "\nCollection is empty.";
            return Type();
        }

        Type Max = Kollection[0];
        for (int i = 1; i < NumElements; i++)
        {
            if (Kollection[i] > Max)
            {
                Max = Kollection[i];
            }
        }
        return Max;
    }

    ~Collection()
    {
        if (Kollection != 0)
        {
            delete[] Kollection;
            Kollection = 0; // Setting pointer to 0 after deletion
        }
    }
};

int main()
{
    Collection<int> intCollect;
    Collection<float> floatCollect;
    Collection<char> charCollect;
    int Choice, Type;

    do
    {
        cout << "\n\n~Data Type Collections~"
             << "\nChoices:"
             << "\n1. Enter a New Collection"
             << "\n2. Display all Collections"
             << "\n3. Reverse a Collection"
             << "\n4. Find Maximum value in a Collection"
             << "\n0. Exit"
             << "\nEnter your Choice: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            cout << "\nChoose Data Type of Collection:"
                 << "\n1. Integer"
                 << "\n2. Float"
                 << "\n3. Character"
                 << "\nEnter Choice: ";
            cin >> Type;

            if (Type == 1)
                intCollect.InputCollection();
            else if (Type == 2)
                floatCollect.InputCollection();
            else if (Type == 3)
                charCollect.InputCollection();
            else
                cout << "\nIncorrect Choice!";
            break;

        case 2:
            intCollect.Display();
            floatCollect.Display();
            charCollect.Display();
            break;

        case 3:
            cout << "\nChoose Collection to Reverse:"
                 << "\n1. Integer"
                 << "\n2. Float"
                 << "\n3. Character"
                 << "\nEnter Choice: ";
            cin >> Type;

            if (Type == 1)
                intCollect.Reverse();
            else if (Type == 2)
                floatCollect.Reverse();
            else if (Type == 3)
                charCollect.Reverse();
            else
                cout << "\nIncorrect Choice!";
            break;

        case 4:
            cout << "\nMaximum value in Integer Collection: " << intCollect.FindMax()
                 << "\nMaximum value in Float Collection: " << floatCollect.FindMax()
                 << "\nMaximum value in Character Collection: " << charCollect.FindMax();
            break;

        default:
            break;
        }
    } while (Choice > 0 && Choice < 5);

    cout << "\n\nExiting System...";
    return 0;
}
