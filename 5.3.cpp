#include<iostream>
using namespace std;

class point
{
    int x , y;

    public:
        void insert_data()
        {
            cin >> x >> y;
        }
        point operator-()
        {
            point a;
            a.x = -x;
            a.y = -y;
            return a;
        }
        point operator+(point &k)
        {
            point b;
            b.x = x + k.x;
            b.y = y + k.y;
            return b;
        }
        void display()
        {
            cout << x << endl;
            cout << y;
        }
};

int main()
{
    point p1 , p2 , p3;
    p1.insert_data();
    p2 = -p1;
    p2.display();
    p2.insert_data();
    p3 = p1 + p2;
    p3.display();
}
