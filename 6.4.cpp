#include <iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
             cout << "Base Constructor\n";
        }
        virtual ~Base()
        {
             cout << "Base Destructor\n";
            }
};

class Derived : public Base
{
    int* data;

    public:
        Derived()
        {
            data = new int[10];
            cout << "Derived Constructor\n";
        }

        ~Derived()
        {
        delete[] data;
        cout << "Derived Destructor\n";
    }
};

int main()
{
    Base* obj = new Derived();
    delete obj;

    return 0;
}
