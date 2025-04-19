#include<iostream>
using namespace std;

class shape
{
    float r;

    public:
        void get_r()
        {
            cout << "Enter A Radius:";
            cin >> r;
        }
        float radius()
        {
            return r;
        }
}s;

class circle :shape
{
    float a;

    public:
        void cal_area()
        {
            get_r();
            float t = radius();
            a=3.14*(t*t);
        }
        void display_area()
        {
            cout << "Calculated Area is:" << a;
        }
}c;


int main()
{
    cout << sizeof(s) << endl;
    cout << sizeof(c) << endl;
    c.cal_area();
    c.display_area();
}
