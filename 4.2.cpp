#include<iostream>
using namespace std;

class person
{
    char name[20];
    int age;
    public:
        void insert_data()
        {
            cout << "Enter Name:";
            cin >> name;
            cout << "Enter Age:";
            cin >> age;
        }
        void display_data()
        {
            cout << "Name of a person is:" << name << endl;
            cout << "Age of a person is:" << age << endl;
        }

}P;

class employee : public person
{
    int emp_id;
    public:
        void insert_id()
        {
            insert_data();
            cout << "Enter Id:";
            cin >> emp_id;
        }
        void display_id()
        {
            display_data();
            cout << "Id of Employee is:" << emp_id << endl;
        }
}E;

class manager : public employee
{
    char department[25];
    public:
        void insert_department()
        {
            insert_id();
            cout << "Enter Your Department:";
            cin >> department;
        }
        void display_department()
        {
            display_id();
            cout <<"Your Department is:" << department;
        }

}M;

int main()
{
    M.insert_department();
    M.display_department();
}
