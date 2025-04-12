#include<iostream>
using namespace std;

class complex
{
    float a,b;

    public:
        void insert_data()
        {
            cin >> a;
            cin >> b;
        }
        complex operator+(complex &c)
        {
            complex x;
            x.a = a + c.a;
            x.b = b + c.b;
            return x;
        }
        complex operator-(complex &k)
        {
            complex y;
            y.a = a - k.a;
            y.b = b - k.b;
            return y;
        }
        void display_data()
        {
            cout << a;
            if(b >= 0)
            {
                cout << "+";
            }
            cout << b << "i" << endl;
        }
};

int main()
{
    complex c1 , c2 , c3 , c4;
    c1.insert_data();
    c2.insert_data();
    c3 = c1 + c2;
    c4 = c1 - c2;
    c3.display_data();
    c4.display_data();
}
