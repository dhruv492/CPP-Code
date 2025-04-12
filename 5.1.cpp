#include<iostream>
using namespace std;

class calculator
{
    int a,b,z;
    float c,d,r;

    public:
        void add(int x , int y)
        {
            a = x;
            b = y;
            z = a + b;
        }
        void add(float p , float q)
        {
            c = p;
            d = q;
            r = c + d;
        }
        void display()
        {
            cout << z << endl;
            cout << r;
        }
};

int main()
{
    calculator e;
    e.add(1 , 2);
    e.add(2.f , 3.4f);
    e.display();
}
