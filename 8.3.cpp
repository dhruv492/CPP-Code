#include <iostream>
#include <set>

using namespace std;

class UniqueNumberSet
{
private:
    set<int> numbers;

public:
    void inputNumbers()
    {
        int n, x;
        cout << "Enter the number of integers in the set: ";
        cin >> n;

        cout << "Enter " << n << " integers: ";
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            numbers.insert(x);
        }
    }

    void displayNumbers() const
    {
        cout << "Unique Sorted Numbers: ";
        for (const auto& num : numbers)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    UniqueNumberSet uniqueSet;
    uniqueSet.inputNumbers();
    uniqueSet.displayNumbers();

    return 0;
}
