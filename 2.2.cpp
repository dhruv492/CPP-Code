#include<iostream>
using namespace std;

class Student
{
    int ID, m1, m2, m3;
    float AvgMarks;
    string Name;

    void Average()
    {
        AvgMarks = (m1 + m2 + m3) / 3.0;
    }

    public:

    void InputData(int inID = 0, string inName = "Test", int M1 = 0, int M2 = 0, int M3 = 0)
    {
        ID = inID;
        Name = inName;
        m1 = M1;
        m2 = M2;
        m3 = M3;
        Average();
    }

    float ReturnAverage()
    {
        return AvgMarks;
    }

    void ViewData()
    {
        cout << "\n\nID: " << ID;
        cout << "\nName: " << Name;
        cout << "\nMarks:";
        cout << "\nSubject 1: " << m1;
        cout << "\nSubject 2: " << m2;
        cout << "\nSubject 3: " << m3;
        cout << "\nAverage Marks: " << AvgMarks << endl;
    }
};

int main()
{
    Student s[5];
    int ID, m1, m2, m3;
    string Name;

    cout << "\n\nEnter Details of 5 Students:";
    for (int i = 0; i < 5; i++)
    {
        int choice = 0;
        cout << "\n\nDo you want to enter Details for Student " << i + 1 << " ?(Press 1 for yes): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n\nStudent " << i + 1;
            cout << "\nID: ";
            cin >> ID;
            cout << "Name: ";
            cin.ignore();
            getline(cin, Name);
            cout << "\nEnter marks of Student " << i + 1 << ":" << endl;
            cout << "Subject 1: ";
            cin >> m1;
            cout << "Subject 2: ";
            cin >> m2;
            cout << "Subject 3: ";
            cin >> m3;
            s[i].InputData(ID, Name, m1, m2, m3);
            cout << "Average marks of Student " << i + 1 << " is: " << s[i].ReturnAverage() << endl;
        }
        else
        {
            s[i].InputData();
        }
    }

    cout << "\n\nViewing Details of 5 Students:";
    for (int i = 0; i < 5; i++)
    {
        s[i].ViewData();
    }

    return 0;
}
