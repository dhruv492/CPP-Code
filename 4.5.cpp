#include <iostream>

using namespace std;

class Student
{
protected:
    char name[20];
    int marks;

public:
    Student(const char* n, int m) : marks(m)
    {
        int i = 0;
        for (; n[i] != '\0' && i < 19; ++i)
        {
            name[i] = n[i];
        }
        name[i] = '\0';
    }

    virtual void computeGrade() const = 0;
    virtual void displayInfo() const
    {
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }

    virtual ~Student() {}
};

class Undergraduate : public Student
{
public:
    Undergraduate(const char* n, int m) : Student(n, m) {}

    void computeGrade() const override
    {
        cout << "Undergraduate Student Grade: ";
        if (marks >= 90)
            {
            cout << "A" << endl;
        }
        else if (marks >= 75)
        {
            cout << "B" << endl;
        }
        else if (marks >= 50)
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
};


class Postgraduate : public Student
{
public:
    Postgraduate(const char* n, int m) : Student(n, m) {}

    void computeGrade() const override
    {
        cout << "Postgraduate Student Grade: ";
        if (marks >= 85)
        {
            cout << "A" << endl;
        }
        else if (marks >= 70)
        {
            cout << "B" << endl;
        }
        else if (marks >= 55)
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
};

int main()
{
    Student* students[4];
    students[0] = new Undergraduate("Alice", 82);
    students[1] = new Postgraduate("Bob", 76);
    students[2] = new Undergraduate("Charlie", 45);
    students[3] = new Postgraduate("Diana", 90);

    for (int i = 0; i < 4; ++i)
    {
        students[i]->displayInfo();
        students[i]->computeGrade();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i)
    {
        delete students[i];
    }

}
