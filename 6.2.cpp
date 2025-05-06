#include <iostream>
using namespace std;

class Point
{
    int x, y;

    public:
        Point(int x_init, int y_init) : x(x_init), y(y_init) {}

    Point* move(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void display() const
    {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p(10, 20);
    p.display();

    p.move(5, -10)->move(10, 15);
    p.display();

    return 0;
}
