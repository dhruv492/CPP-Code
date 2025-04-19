#include <iostream>
using namespace std;

class Shape
{
    public:
        virtual ~Shape() {}

        virtual double Area() const = 0;

        virtual void Display() const = 0;
};

class Rectangle : public Shape
{
    private:
        double length;
        double width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        double Area() const override
        {
            return length * width;
        }

        void Display() const override
        {
            std::cout << "Rectangle Area: " << Area() << "\n";
        }
};

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}

        double Area() const override
        {
            return 3.14159 * radius * radius;
        }

        void Display() const override
        {
            cout << "Circle Area: " << Area() << "\n";
        }
};

int main()
{
    Rectangle rectangle(10.0, 5.0);
    Circle circle(7.0);

    Shape* shape1 = &rectangle;
    Shape* shape2 = &circle;

    shape1->Display();
    shape2->Display();

    return 0;
}
